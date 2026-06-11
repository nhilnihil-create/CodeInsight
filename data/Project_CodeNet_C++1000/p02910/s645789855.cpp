//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define For_Arr     for(i=0;i<n;i++)
using namespace std;
int main()
{
    ll n,i;
    string s;
    cin>>s;
    bool ok=1;
    for(i=0; s[i]; i++)
    {
        if((i+1)%2&&(s[i]=='R'||s[i]=='U'||s[i]=='D'));
        else if((i+1)%2==0&&(s[i]=='L'||s[i]=='U'||s[i]=='D'));
        else
        {
            ok=0;
            break;
        }
    }
    if(ok)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}



