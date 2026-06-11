#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define infin ll (pow(10,9)+7);
int main()
{
    ll n,d,x,y;
    cin>>n>>d;
    int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if((x*x)+(y*y)<=(d*d))
        {
          count+=1;
          //cout<<i+1<<" this one"<<endl;
        }
    }
    cout<<count<<endl;
}