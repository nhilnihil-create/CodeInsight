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
    string s[n];
    map<string,ll>m;
    ll c=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
        c+=m[s[i]];
        m[s[i]]++;
    }
    cout<<c<<endl;



}
//Alhamdulillah







