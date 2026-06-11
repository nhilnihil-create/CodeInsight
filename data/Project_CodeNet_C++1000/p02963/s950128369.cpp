// #Sazaの1日1AC
#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
const long long INF=9e15;
const double PI=3.14159265358979323846;

//マクロ
//型エイリアス
using ll = long long;
using P=pair<long long,long long>;
using vl=vector<long long>;
using vvl=vector<vector<long long>>;
using vP=vector<pair<long long, long long>>;
//ショートカット
#define rep(i,n) for(long long i = 0; i < n; i++)
#define rep2(i,k,n) for(long long i = k; i < n; i++) //半開区間
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mkp make_pair
//入力
#define vin(v,N) for(long long id=0;id<N;id++) cin>>v.at(id)
#define lin(n) long long n;cin>>n
#define chin(x) char x;cin>>x;
#define sin(s) string s;cin>>s;
#define vlin(v,N) vector<long long>v(N);for(long long i=0;i<N;i++)cin>>v.at(i)

#define max(a,b) max((ll)a,(ll)b)
#define min(a,b) min((ll)a,(ll)b)

//関数
//最大公約数
long long gcd(long long m, long long n){
  long long a=max(m,n);
  long long b=min(m,n);
  long long r=a%b;
  while(r!=0){
    a=b; b=r; r=a%b;
  }
  return b;
}
// 最小公倍数
long long lcd(long long m, long long n){
  return m*n/gcd(m,n);
}
//xのn乗
long long power(long long x, long long N){
  long long ret=1;
  for(long long i=0;i<N;i++)   
    ret*=x;
  return ret;
}
//繰り返し二乗法
long long repeat_squaring(long long x, long long n){
  if(n==0) return 1;
  else if(n%2==0){
    long long t=repeat_squaring(x,n/2);
    return t*t%mod;
  }
  else
    return x*repeat_squaring(x,n-1);
}
//素因数分解(mapで返す)
map<long long,long long> factor(long long p){
  ll p1=p;
  map<long long,long long>ret;
  for(long long i=2;i*i<=p1;i++){
     while(p%i==0){
      ret[i]++;
      p/=i;
    }
  }
  if(p!=1)
  ret[p]++;
  return ret;
}
//素数判定
bool is_prime(long long N){
  for(long long i=2;i*i<=N;i++){
    if(N%i==0)
      return false;
  }
  return true;
}
//最大値更新
void chmax(long long &a,long long b){
  a=max(a,b);
}
//最小値更新
void chmin(long long &a,long long b){
  a=min(a,b);
}

//構造体

/////////////////⊂('ω'⊂ )))Σ≡GO!/////////////////

//メイン関数
int main(){
  //doubleの桁数
  cout<<fixed<<setprecision(2);
  
  lin(S);

  ll p =(ll)floor(sqrt(S));

  ll i = p, j = p;

  while(true){
    if((i - 1) * (i - 1) < S && S <= i * i){
      p = i; break;
    }
    if((j - 1) * (j - 1) < S && S <= i * i){
      p = j; break;
    }

    i++; j--;

  }

  ll q = -S + p*p;


  cout << p << " " << 1 << " " << q <<" " << p << " " << "0 0" << endl;
}