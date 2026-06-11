#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end() 
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    speed;
    int n; cin >> n;
    vi v(n); 
    int mod = 1e9 + 7ll;
    vector<int> data(61);
    rep(i, 0, n) {
        cin >> v[i];
        int k = v[i];
        int cnt = 0;
        while(k != 0) {
            data[cnt++] += k % 2;
            k /= 2;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        vector<bool> visited(61);
        int k = v[i];
        int cnt = 0;
        while(k != 0) {
            visited[cnt++] = k % 2;
            k /= 2;
        }
        rep(j, 0, 61) {
            k = pow(2, j);
            k %= mod;
            if(visited[j]) {
                sum += (k * (n - i - data[j])) % mod;
            } else {
                sum += (k * data[j]) % mod;
            }
            sum %= mod;
            if(visited[j]) data[j]--;
        }
    }
    sum %= mod;
    cout << sum << endl;
    return 0;
}