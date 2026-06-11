#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int MAXN = 10 + 1e5;
const long long oo = 1 + 1e18;
typedef long long LL;
typedef pair < int, int > II;
typedef pair < int, II > III;

int n, d[MAXN], top = 0, L[MAXN], R[MAXN], id[MAXN];
long long a[MAXN];

int main()
{
    #define TASK "ABC"
  //  freopen(TASK".inp","r",stdin);
 //   freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        id[a[i]] = i;
    }
    long long ans = 0;
    a[0] = a[n+1] = oo;
    multiset < int > s;
    s.insert(0);
    s.insert(0);
    s.insert(n+1);
    s.insert(n+1);
    for (int i = n - 1; i >= 1; i--){
        s.insert(id[i+1]);
        auto it1 = s.lower_bound(id[i]);
        auto it2 = it1;
        it1--;
        int l1 = *it1--, l2 = *it1;
        int r1 = *it2++, r2 = *it2;
        ans += LL(i) * LL( (l1 - l2) * (r1 - id[i]) + (r2 - r1) * (id[i] - l1) );
      //  cout << ans << endl;
    }
    cout << ans;



    return 0;
}


