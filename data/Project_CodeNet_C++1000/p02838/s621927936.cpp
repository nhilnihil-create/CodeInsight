#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007

int main(){
    ll N;
    ll ans = 0;
    cin >> N;
    vector<ll> d(61, 0);
    for(int i = 0; i < N; i++){
        ll A;
        cin >> A;
        for(int j = 59; j >= 0; j--){
            ll c = pow(2, j);
            if(A >= c){
                d[j]++;
                A -= c;
            }
        }
    }
    for(int i = 0; i <= 59; i++){
        ll cnt = (N - d[i]) * d[i];
        cnt %= MOD;
        ll cc = pow(2, i);
        cc %= MOD;
        ll c = cc * cnt;
        c %= MOD;
        ans += c;
        ans %= MOD;
    }
    cout << ans << endl;
}