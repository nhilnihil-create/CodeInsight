// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

bool is_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    if(n==1) return false;
    return true;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n;
    ll a,b;
    ll k,t;
    string str;
    cin>>str;
    vector<ll> l(str.length()+1);
    vector<ll> r(str.length()+1);
    for(ll i=1;i<=str.length();i++){
        if(str[i-1]=='<') l[i]=l[i-1]+1;
    }
    reverse(all(str));
    for(ll i=1;i<=str.length();i++){
        if(str[i-1]=='>') r[i]=r[i-1]+1;
    }
    reverse(all(str));
    ll sum=0;
    reverse(all(r));
   // rep(i,str.length()) cout<<" "<<str[i]<<" ";
    //ln;
   // rep(i,str.length()+1){
   //     cout<<l[i]<<"  ";
   //         }ln;
    rep(i,str.length()+1){
     //   cout<<r[i]<<"  ";
        sum+=max(l[i],r[i]);
    }
    cout<<sum<<endl;
    return 0;
}
