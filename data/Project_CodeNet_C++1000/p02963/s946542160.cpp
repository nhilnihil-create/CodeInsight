#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long s;
const long long u=1e9;
int main()
{
    cin>>s; 
    if(s==1e18)  cout<<"0 0 "<<u<<" 0 0 "<<u<<endl;
    else
    {
        cout<<"0 0 ";
        long long p=s/u,k=s%u;
        k=u-k;
        cout<<p+1<<" "<<u-(s%u)<<" ";
        cout<<1<<" "<<u<<endl;
        
    }
    return 0;

}