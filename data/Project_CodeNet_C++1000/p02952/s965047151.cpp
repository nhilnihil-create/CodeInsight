//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,j,ans=0;
    cin>>n;
    string s;
    for(i=1;i<=n;i++){
    s=to_string(i);
    if(s.length()%2) ans++;
    }
        cout<<ans<<endl;
    return 0;
}



