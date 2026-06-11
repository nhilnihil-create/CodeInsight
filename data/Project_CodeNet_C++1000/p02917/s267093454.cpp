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
    int b[n];

    for(int i=0;i<n-1;i++)
    {
        cin>>b[i];
    }
    ll sum=b[0];
        for(int i=0;i<n-2;i++)
        {
            if(b[i]<=b[i+1])
                sum+=b[i];
            else
                sum+=b[i+1];
        }
        sum+=b[n-2];
        cout<<sum<<endl;

}
//Alhamdulillah
















