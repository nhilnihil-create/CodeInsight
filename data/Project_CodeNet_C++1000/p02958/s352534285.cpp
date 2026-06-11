//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,j,misplaced=0;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=0; i<n; i++)
    {

        if(i+1!=a[i])
            misplaced++;
    }
    if(misplaced==0||misplaced==2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}



