#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    ll n;
    cin>>n;
    ll t=26;
    int cnt=1;
    while(n>t){
        n-=t;
        t*=26;
        ++cnt;
    }
    --n;
    vector<char> v;
    rep(i,cnt){
        int r=n%26;
        v.push_back('a'+r);
        n/=26;
    }
    for(auto i=v.rbegin();i!=v.rend();++i){
        cout<<*i;
    }
    cout<<endl;
}
