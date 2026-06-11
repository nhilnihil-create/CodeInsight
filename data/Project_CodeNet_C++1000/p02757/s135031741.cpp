#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}


int anss[20000];

int extgcd(int a, int b, int &x, int &y) {
    int g = a;
    x = 1;
    y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int mod_fact(int n,int p,int& e){
  e = 0;
  if(n==0) return 1;
  int res = mod_fact(n/p,p,e);
  e += n/p;
  if(n/p%2 != 0){
    //n!(mod p)を求める
    int t = 1;
    for(int i=1;i<=n;i++){
      t *= i;
      t %= p;
    }
    //ここまで
    return res*(p-t)%p;
  }
  //n!(mod p)を求める
  int t2=1;
  for(int i=1;i<=n;i++){
    t2 *= i;
    t2 %= p;
  }
  //ここまで
  return res * t2%p;
}

int mod_inverse(int a,int m){
  int x,y;
  extgcd(a,m,x,y);
  return (m+x%m) %m;
}

int mod_comb(int n,int k,int p){
  if(n<0||k<0||n<k) return 0;
  int e1,e2,e3;
  int a1 = mod_fact(n,p,e1),a2 = mod_fact(k,p,e2),a3 = mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1 * mod_inverse(a2*a3%p,p)%p;
}


signed main(){
    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    int ans = 0;
    if(p==2){
        REP(i,s.size()){
            if((s[i]-'0')%2 == 0){
                ans += i+1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    else if(p==5){
        REP(i,s.size()){
            if((s[i]-'0')%5 == 0){
                ans += i+1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    int now = 0;
    int keta = 1;
    REP(i,s.size()){
        now += keta * (int)(s[s.size()-1-i]-'0');
        now %= p;
        anss[now] ++;
        keta *= 10;
        keta %= p;
    }
    
    anss[0] ++;
    REP(i,p){
      //cout << i << " " <<  anss[i] << endl;
        if(anss[i] <= 1) continue;
        ans += anss[i] * (anss[i] -1) /2;
    }
    cout << ans << endl;
    return 0;
}