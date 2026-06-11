//Radhe Radhe
#include<bits/stdc++.h>//14 JUL 2020
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll n,i,j,m,ans=0;
    cin>>n>>m;
    ans=(n*(n-1))/2;
    ans+=(m*(m-1))/2;

    cout<<ans<<endl;
    return 0;
}



