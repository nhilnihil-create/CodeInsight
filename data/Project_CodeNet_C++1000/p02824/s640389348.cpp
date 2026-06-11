#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)1e9 + 5)
#define MAXL ((ll)1e15 + 5)
#define MAX_X ((int)1e5 + 2)
#define pi (2.0*acos(0))
#define M ((int)1e6 + 7)
#define MOD ((int)998244353 + 0)
#define NN ((int)1e5 + 7)
#define N ((int)1e5 + 5)
#define eps (0)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define logn 29
#define endl "\n"
#define mp make_pair
//#define int ll


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/




typedef tree < pair < int, pair < int, int > >,  null_type,  less < pair < int, pair < int, int > > >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
/// o_set s;
/// s.order_of_key(k) : Number of items strictly smaller than k .
/// *(s.find_by_order(k)) : K-th element in a set (counting from zero).

bool cmp(int a , int b)
{
    return a>b;
}

int arr[N];

int srch(int l , int r , int arr[], int a)
{
    while(l<r){
        int m = (l+r+1)>>1;
        if(arr[m]>a) l = m;
        else r = m - 1;
    }
    if(arr[l]>a) return l+1;
    return l;
}

ll cum[N];

int main()
{
    fastio;
    int n , m , v , p;
    cin>>n>>m>>v>>p;
    for(int i = 1 ; i<=n ; i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1,cmp);
    for(int i = 1 ; i<=n ; i++) cum[i] = cum[i-1] + arr[i];
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(arr[i]>=arr[p]) ans++;
        else if(arr[i]+m>=arr[p]){
            int pos = srch(1,n,arr,arr[i]);
            int tot = n-pos;
            ll rem = v - tot - p;
            rem *= m;
            ll sum = cum[pos-1]-cum[p-1];
            sum = (ll)(pos-1-p+1)*(arr[i]+m) - sum;
            if(sum>=rem) ans++;
        }
        //else cout<<arr[i]<<" ";
    }
   // cout<<endl;
    cout<<ans<<endl;
    return 0;
}
