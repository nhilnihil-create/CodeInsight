#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    //int c=0;
    while(t--) {
       string s;
       ll n,i,j;
       cin>>s;
       n=s.length();
       if(s[n-1]=='s')
        s+="es";
       else
        s+='s';
       cout<<s;
    }

}
