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
    int n;
    cin>>n;
    string s,s1="",s2="";
    cin>>s;
    if(n%2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<(n/2);i++)
        s1+=s[i];
    for(int i=n/2;i<n;i++)
        s2+=s[i];
        if(s2==s1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;


}












