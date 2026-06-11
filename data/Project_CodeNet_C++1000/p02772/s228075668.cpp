#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
Apparently, the tree supports the same operations as the set 
(at least I haven't any problems with them before), but also there are two new features — 
find_by_order() — The first returns an iterator to the k-th largest element (counting from zero)
order_of_key() — the number of items in a set that are strictly smaller than our item. 
https://codeforces.com/blog/entry/11080
using namespace __gnu_pbds; */
using namespace std;
#define test() int t;cin>>t;for(int test=1;test<=t;test++)
#define int long long
#define MOD 1000000007
#define pb push_back 
#define ins insert
#define fast(); ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ld long double
#define endl '\n'
int m(int a) {
    return ((a%MOD)+MOD)%MOD;
}
int p(int a, int b) {
    int res = 1;
    while(b > 0){
        if(b&1) res = m(m(res)*m(a));
        a = m(m(a)*m(a));
        b >>= 1;
    }
    return res;
}
// vector<int> fac; //precompute fac array
// fac.resize(n+1);
// fac[0] = 1; 
// for (int i=1; i<=n; i++)   fac[i] = m(m(fac[i-1])*m(i));
// int modInverse(int n){ 
// return p(n, MOD-2); 
// }  
// int nCrModPFermat(int n, int r){   
//     if(r == 0)  return 1; 
//     return m(m(m(fac[n])*m(modInverse(fac[r])))*m(modInverse(fac[n-r]))); 
// } 
signed main(){
    fast();
    int n;
    cin >> n;
    bool flag = false;
    for(int i=0, f; i<n; i++){
        cin >> f;
        if(f%2 == 0){
            if(f%3 != 0 && f%5 != 0){
                flag = true;
            }
        }
    }
    if(flag)    cout << "DENIED" << endl;
    else cout << "APPROVED" << endl;
    cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}