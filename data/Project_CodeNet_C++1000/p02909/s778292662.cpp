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
    if(s[0]=='C')
        cout<<"Rainy"<<endl;
    else if(s[0]=='R')
        cout<<"Sunny"<<endl;
    else
        cout<<"Cloudy"<<endl;




}
//Alhamdulillah






















