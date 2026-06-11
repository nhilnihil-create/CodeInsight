#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, L; cin >> N >> L;
    int sum = 0;
    rep(i, N){
        sum += L + i;
    }
    ll diff = INF;
    int ans = 0;
    rep(i, N){
        int tmp = sum - (L + i);
        if(abs(tmp - sum) < diff){
            ans = tmp;
            diff = tmp - sum;
        }
    }
    cout << ans << endl;
}