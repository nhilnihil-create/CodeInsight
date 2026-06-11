//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int main() {
    fastIO;
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum_xor=0;
    for(int i:arr) sum_xor^=i;

    for(int i: arr) cout<<(sum_xor^i)<<" ";

    return 0;
}