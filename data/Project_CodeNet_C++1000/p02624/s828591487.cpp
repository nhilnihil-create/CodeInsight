#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl '\n'

int const N = 10000001;
int f[N];

void sieve(int n){
    for (int p=1; p<=n; p++){
        f[p]++;
        for (int i=p*2; i<=n; i+=p) f[i]++;
    }
}

void solvetask(){
    int n; cin >> n;
    sieve(n);
    long long ans = 0;
    for (long long i = 1; i <= n; i++) ans += i * (long long) f[i];
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;// cin >> t;
    while(t--) solvetask();
}