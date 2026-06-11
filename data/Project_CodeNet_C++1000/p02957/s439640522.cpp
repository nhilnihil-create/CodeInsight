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
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    int n,m;
    cin>>n>>m;
    if(n%2!=m%2)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<(n+m)/2<<endl;


}
//Alhamdulillah




