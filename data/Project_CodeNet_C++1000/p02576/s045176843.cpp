#include<bits/stdc++.h>
#define sio(); ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fio(); freopen("input","r",stdin); freopen("output","w",stdout);
using namespace std;
int main()
{
    double n,x,t;
    int k;
    cin>>n>>x>>t;
    k = n/x;
    if((n/x)>k)k = (n/x)+1;
    printf("%d\n",int(k*t));
    return 0;
}
