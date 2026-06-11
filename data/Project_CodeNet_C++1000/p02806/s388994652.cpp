#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);

int main(){
    int n,d=0,x;
    cin>>n;
    vector<pair<string,int>> vec(n);
    string s,t;
    rep(i,n){
        cin>>t>>x;
        vec[i]=make_pair(t,x);
    }
    cin>>s;
    int ans=0;
    rep(i,n){
        if(d==1){
            ans+=vec[i].second;
        }
        if(vec[i].first==s){
            d=1;
        }
    }
    cout<<ans<<endl;
}