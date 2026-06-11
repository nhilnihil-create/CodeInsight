#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define ll long long int
#define pi 3.141592653589793238
const int N = 1e5 + 10;
int main(){
    FAST;
    ll t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length()-1;
        if(s[n]=='s')
            cout<<s<<"es";
        else
            cout<<s<<"s";
    }
    return 0;
}
