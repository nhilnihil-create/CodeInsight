#ifdef loc
    #include "../codes/loc_debug.h"
#else
    #include <bits/stdc++.h>
    #define pr(...)
    #define pra(a,n)
    #define praa(a,n,m)
    #define prl()
#endif
using namespace std;

typedef long long ll;
#define sz(a) int(a.size())
const int N = 100005;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<(n-1)/2<<endl;
    return 0;
}