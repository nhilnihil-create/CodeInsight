#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
    ll n,i,j,p,r,l,sum=0,k;
    vector<vector<int> >v(10,vector<int>(10));
    cin>>n;
    for(i=1;i<=n;i++){
    p=i;
    r=p%10;
    while(p!=0)
    {
        l=p%10;
        p=p/10;
    }
    k=l;
    v[k][r]++;
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            sum+=v[i][j]*v[j][i];
    }
    cout<<sum;
}
