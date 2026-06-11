#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
// #define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N];
string s;

int32_t main()
{
    int n  ; cin >> n ;
    for(int i = 0; i < n ; ++i) cin >> A[i+1];
    int ans = 1e8;
    for(int p = 1 ; p <= 100 ; ++p){
        int sum = 0;
        for(int i = 1 ; i <= n ; ++i){
            sum += (A[i]-p) * (A[i]-p);
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}