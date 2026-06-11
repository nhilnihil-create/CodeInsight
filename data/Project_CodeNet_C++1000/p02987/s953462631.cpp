//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,x,alp[26]={0},cnt=0;
    string s;
    cin>>s;
    for(i=0; s[i]; i++)
    {
        x=s[i]-'A';
        alp[x]++;
    }
    for(i=0; i<26; i++)
    {
        if(alp[i]==2) cnt++;
    }

if(cnt==2)

    cout<<"Yes"<<endl;
 else   cout<<"No"<<endl;




    return 0;
}



