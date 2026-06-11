#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define sint int32_t
#define int long long int
#define all(v) v.begin() , v.end()
#define vii vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int arr[100];
int n;


int32_t main()
{   fastio;

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int ans = 1000;
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<n; i++) {
        if(arr[i]>arr[i-1]) {
            int p = arr[i-1];

            cnt = ans/p;
            sum = ans%p;

            sum += cnt*arr[i];

            ans = max(ans , sum);
            sum = 0;
        }
    }
    cout<<ans<<"\n";

}