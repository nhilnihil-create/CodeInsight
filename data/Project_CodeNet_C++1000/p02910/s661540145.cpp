//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    string s;
    cin>>s;
    int ok=1;
    for(int i=0;s[i];i++)
    {
        if(i%2)
        {
            if(s[i]=='R')
            {
                ok=0;
                break;
            }
        }
        else
        {
            if(s[i]=='L')
            {
                ok=0;
                break;
            }
        }
    }
    if(ok)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;




}
//Alhamdulillah























