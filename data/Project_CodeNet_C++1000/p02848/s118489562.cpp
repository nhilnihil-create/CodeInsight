//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll n,i;
    string s;
    cin>>n>>s;
    for(i=0;s[i];i++)
    {
    ll x=s[i]-'A';
    x+=n;
    x%=26;
    s[i]=x+'A';
    }
    cout<<s<<endl;


    return 0;
}



