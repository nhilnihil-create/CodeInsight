#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    int n,m;
    cin>>n>>m;
    int sum=0;
    int a=(n*(n-1))/2;
    int b=(m*(m-1))/2;
    if(a>=0)sum+=a;
    if(b>=0)sum+=b;
    cout<<sum<<endl; 
}
