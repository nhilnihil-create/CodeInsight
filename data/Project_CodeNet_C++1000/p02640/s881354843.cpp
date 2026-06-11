#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl '\n'
 
int t=1;
 
// void print2d(vector<vector<int>> &v){
//     for(int i=0;i<v.size();i++){
//         for(int x:v[i]){
//             cout << x <<' ';
//         }
//         cout <<endl;
//     }
// }
 
// void print(vector<int> &a){
//     for(int x : a){
//         cout << x <<' ';
//     }
//     cout << endl;
//     return;
// }

void solve(){
    int n,l;
    cin >> n >> l;
    for(int i=0;i<=n;i++){
        if((l+2*i)==4*n){cout << "Yes" <<endl;return;}
    }
    cout << "No" <<endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    // cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
    // solve();
 
    return 0;
}
