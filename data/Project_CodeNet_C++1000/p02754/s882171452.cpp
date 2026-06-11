#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli c,n,a,b,cnt;
    cin>>n>>a>>b;
     c=a+b;
    cnt=n/c;
    cnt=cnt*a;
     
    cnt+=min(n%c,a);
    
     cout<<cnt<<"\n";
}