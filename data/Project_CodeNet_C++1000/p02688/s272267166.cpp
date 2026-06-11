#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k, d;
    cin >> n >> k;
    int ans = n;
    int a[n] = {};
    while(k--) {
        cin >> d;
        while(d--) {
            int t;
            cin >> t;
            if(a[t-1] == 0) {
                --ans;
                a[t-1] = 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

