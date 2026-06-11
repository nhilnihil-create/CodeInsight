#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,m,val;
cin>>n>>m>>val;
if(m>n)
    swap(n,m);
int x=val/n;
if(val%n!=0)
    x++;
cout<<x<<endl;
    return 0;
}
