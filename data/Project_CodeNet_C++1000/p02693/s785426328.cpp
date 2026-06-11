#include<bits/stdc++.h>
#define     fast                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll                      long long
#define     pb                      push_back
#define     M                       1000000007
using namespace std;
int main()
{
    ll m,n,x,y,sum=0;
    cin>>n>>x>>y;
    m = x%n;
    if(x%n==0) cout<<"OK"<<endl;
    else if((n-m)<=(y-x)) cout<<"OK"<<endl;
    else cout<<"NG"<<endl;


}
