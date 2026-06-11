#include<bits/stdc++.h>
using namespace std;
#define start ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i, a, n) for( i=a; i<n;i++)
#define rr return 0;
const int N = (int)(1*1e6+10);
int fen[N];
typedef long long ss;
int main()
{
    start;
    ss i,j,n,m,a,b;
    cin>>a>>b;
    n=abs(a+b);
    if(n%2==0)
    {
        cout<<n/2<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    rr
}
