#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ARB ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
int main()
{
    ARB
    int arr[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;
    cin>>k;
    k--;
    cout<<arr[k];
}