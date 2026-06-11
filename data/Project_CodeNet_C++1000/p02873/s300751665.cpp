#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
const long long MOD = 1000000007;

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//コンビネーション
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}
//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//切り上げの割り算は(a + b - 1) / bでできる
//時間を意識しろ
//コードテストちゃんとして
//画面とにらめっこするな書け
//WA出すたびにABCは五億円払え
//わからない問題はとばせ
//躊躇なくぐぐれ

//ここから
int main(){
    string S;
    cin>>S;
    ll Ans=0;
    vl l(S.size()+1,0);
    vl r(S.size()+1,0);
    for(ll i=1;i<=S.size();i++){
        if(S.at(i-1)=='<'){
            l.at(i)=l.at(i-1)+1;
        }
    }
    for(ll i=S.size()-1;i>=0;i--){
        if(S.at(i)=='>'){
            r.at(i)=r.at(i+1)+1;
        }
    }
    rep(i,S.size()+1){
        Ans+=max(l.at(i),r.at(i));
    }
    cout<<Ans<<endl;
}

