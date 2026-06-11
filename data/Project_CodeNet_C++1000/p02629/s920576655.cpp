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
    string ans;
    while(n>0){
        --n;
        ans+='a'+n%26;
        n/=26;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
