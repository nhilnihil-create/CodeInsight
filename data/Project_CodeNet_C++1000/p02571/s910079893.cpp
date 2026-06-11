#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
using namespace std;
const int mod=1e9+7;

ll solve(){
    string s,t;
    cin>>s>>t;
    int ans=t.size();
    for(int i=0;i<=s.size()-t.size();i++){
        int tmp=0;
        for(int j=0;j<t.size();j++){
            if(s[i+j] != t[j]) tmp++;
        }
        ans=min(ans,tmp);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
