#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double


using namespace std;
const int N = 500777;
int n, t, x, k;
int a[N];
int suf[N];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	//freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <= n; i++){
        cin >> a[i];
    }
    for (int i = n; i >= 0; i--){
        suf[i] = suf[i + 1] + a[i];
    }
    int cur = 1;
    int sum = 0;
    if (a[0] > 1){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        sum += cur;
        //cout << cur << endl;
        if (a[i] >= cur){
            cout << -1 << endl;
            return 0;
        }
        cur -= a[i];
        if (cur > suf[i + 1]){
            cout << -1 << endl;
            return 0;
        }
        cur = min(suf[i + 1], cur *= 2);
    }
    sum += cur;
    if (cur < a[n]){
        cout << -1 << endl;
        return 0;
    }
    cout << sum << endl;
}
