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
    int a[n],f=1,m=0;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m=max(a[i],m);
            if(a[i]<m-1)
                f=0;
        }

    if(f)
        cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;



}
//Alhamdulillah

















