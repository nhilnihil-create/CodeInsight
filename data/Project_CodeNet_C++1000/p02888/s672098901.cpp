#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define sint int32_t
#define int long long int
#define all(v) v.begin() , v.end()
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



int32_t main()
{   fastio;

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr , arr+n);

    int cnt = 0;
    //cout<<"HELP\n";
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n-1; j++) {
            auto p = lower_bound(arr+j+1 , arr+n , arr[i]+arr[j]);

            //if(*p == arr[i]+arr[j])
            p--;
            int d = p - arr - j;


            cnt += d;
        }
    }

    cout<<cnt<<endl;

}
