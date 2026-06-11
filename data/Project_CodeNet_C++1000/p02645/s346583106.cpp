#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string str,ans;
    cin>>str;
    ans=str.substr(0,3);
    cout<<ans<<endl;
    return 0;
}
