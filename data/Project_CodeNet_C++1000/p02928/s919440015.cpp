#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 20005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans = 0, N, K, cur;
int nums[MAXN][2] = {};
vi A;

void print_table(){
    rep(i, N){
        cout << nums[i][0] << " " << nums[i][1] << endl;
    }
}

void solve(){

    rep(i, N){
        cur = A[i];
        rep(j,N){
            if(cur > A[j]){
                nums[i][0]++;
                if(i < j) nums[i][1]++;
            }
        }
    }

    rep(i,N){
        ans += K * nums[i][1];
        ans %= MOD;
        ans += nums[i][0]*((K*(K-1)/2)%MOD);
        ans %= MOD;
    }

    // print_table();

    cout << ans << endl;
}

int main(){
    cin >> N >> K;
    A.resize(N);

    rep(i, N) cin >> A[i];

    solve();
}
