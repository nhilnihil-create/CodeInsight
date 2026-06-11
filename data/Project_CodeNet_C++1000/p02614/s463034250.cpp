#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;
#define F first
#define S second
#define T second.first
//#define C second.second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define OO 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll,pair<ll,ll>> piii;
const int N = 2e5+5, M= 20, mod = 1000000000;
const double EPS = 1e-10;


int main(){
    FIO
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n, m, k;
    cin>>n>>m>>k;

    char A[7][7];
    int cnt[7] = {0}, cnt2[7] = {0};
    int tot = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
            if(A[i][j] == '#')cnt[i]++, cnt2[j]++, tot++;
        }
    }
    int ans = 0;
    for(int i=0; i<(1<<n); i++){
        vector<int>row;
        for(int j=0; j<n; j++){
            if((i>>j)&1){
                row.push_back(j);
            }
        }

        for(int msk=0; msk<(1<<m); msk++){
            vector<int>col;
            for(int j=0; j<m; j++){
                if((msk>>j)&1){
                    col.push_back(j);
                }
            }
            sort(all(col));
            int sum = 0;
            for(int z: row){
                sum+=cnt[z];
                for(int z2: col){
                    if(A[z][z2] == '#')sum--;
                }
            }
            for(int z: col)sum+=cnt2[z];


            if(tot-sum == k){
                ans++;
            }
        }
    }
    cout<<ans;
}
