#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(a) a.size()
using namespace std;

int n, k, a[200001], ans;

bool ok(int x){
    int tk = k;
    for(int i=0; i<n; i++){
        tk -= (a[i]-1)/x;
        if(tk<0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    int lb = 1, rb = ans;
    while(lb<rb){
        int mid = (lb+rb)/2;
        if(ok(mid)){
            ans = mid;
            rb = mid;
        }
        else lb = mid+1;
    }
    cout << ans << endl;
}
