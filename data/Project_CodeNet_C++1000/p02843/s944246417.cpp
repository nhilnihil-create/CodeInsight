#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
using namespace std;
int main()
{
    ll a,b,i,j,n,k;
    cin>>n;
    while(n)
    {
        //cout<<n<<endl;
        if(n<100) break;
        a=n%10;
        if(n%100>=10 && n>100) a=5;
        else if(a>5) a-=5;
        a+=100;
        n-=a;
    }
    if(n==0) cout<<"1";
    else cout<<"0";
}