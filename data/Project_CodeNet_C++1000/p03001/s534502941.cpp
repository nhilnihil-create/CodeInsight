#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const ll mod=1e9+7;
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    double w,h,x,y;
    cin>>w>>h>>x>>y;
    cout<<fixed<<setprecision(6)<<(w*h)/2.0;
    if(2*x==w&&2*y==h)
        cout<<" "<<1<<endl;
    else
        cout<<" "<<0<<endl;






}















































