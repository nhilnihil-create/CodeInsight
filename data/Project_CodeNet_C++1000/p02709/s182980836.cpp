#include<bits/stdc++.h>
#define ll long long
#define xx first
#define yy second
using namespace std;
ll mem[2003][2003], n;
typedef pair<ll, int>pi;
pi p[2003];
ll dp(int l, int r)
{
    if(l>r)return 0;
    if(mem[l][r]!=-1)return mem[l][r];
    int pos= l+n-r-1;
    return mem[l][r]= max(p[pos].xx*abs(p[pos].yy-l)+dp(l+1, r), p[pos].xx*abs(p[pos].yy-r)+dp(l, r-1));
}
int main()
{
    scanf("%lld", &n);
    for(int i=0; i<n; i++)
    scanf("%lld", &p[i].xx), p[i].yy= i;
    sort(p, p+n, greater<pi>());
    memset(mem, -1, sizeof mem);
    printf("%lld\n", dp(0, n-1));
    return 0;
}
