#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ARB ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define bp  __builtin_popcount
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
const  double EPS = 1e-14;
const ll mod=(ll)1e9+7;
int n;
ll k;
int arr[maxn];
int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int x=0,y=0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        {
             if(arr[i]>arr[j])
                x++;
            if(arr[i]!=arr[j])
                y++;
        }
    cout<<(k*x+k*(k-1)/2%mod*y)%mod;
}
