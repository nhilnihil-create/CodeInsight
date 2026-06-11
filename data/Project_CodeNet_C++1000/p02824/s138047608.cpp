#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, int> pii;


int main()
{
    lli n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<lli> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end(), greater<lli>());

    lli lo = p, hi = n-1, mid, ans = p-1;
    while(lo <= hi){
        mid = (hi+lo)/2;
        lli x = a[mid]+m;
        lli ex = (v-1)-(n-mid-1);
        lli pp = p;
        ex -= (pp-1);
        ex *= m;
        bool fl = true;
        for(lli i=pp-1; i<mid; i++){
            if(a[i] > x)fl = false;
            else{
                ex -= (x-a[i]);
            }
        }
        if(fl) fl = ex <= 0LL;
        if(fl){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout << ans+1 << "\n";

    return 0;
}
