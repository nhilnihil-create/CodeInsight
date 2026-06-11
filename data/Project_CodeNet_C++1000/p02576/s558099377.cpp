#include<bits/stdc++.h>
using namespace std;


#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"

typedef long long ll;

int main()
{
   ll n,x,t;

   cin>>n>>x>>t;

   ll r = n/x;

   if(n%x==0)
    cout<<t*r<<endl;
   else
    cout<<(r+1)*t<<endl;
}
