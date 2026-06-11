#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e6;

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,p,T,cas=0;
    string s;
    cin>>n>>p>>s;
    ll res=0;
    if(p==2||p==5) {
        for(int i=0;i<n;++i) {
            if((s[i]-'0')%p==0) res+=i+1;
        }
    }
    else {
        map<int, int> mp;
        mp[0]=1;
        int pow10=1, r=0;
        for(int i=n-1;i>=0;--i) {
            r = (r + (s[i]-'0')*pow10)%p;
            res += mp[r];
            mp[r]++;
            pow10 = (pow10*10)%p;
        }
    }
    cout<<res<<endl;
    return 0;
}