#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
ll A[200010];
ll sum[200010];
ll K;
ll ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
    }

    map<ll, int> mp;
    for(int i = 0; i <= N; i++){
        if(i - K >= 0) mp[(sum[i - K] - i + K) % K]--;
        ans += mp[(sum[i] - i) % K]++;
    }
    
    cout << ans << endl;
    return 0;
}