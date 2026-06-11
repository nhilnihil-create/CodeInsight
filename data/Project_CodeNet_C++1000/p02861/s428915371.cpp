#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

double dist(ll x1, ll x2, ll y1, ll y2){
    double d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    return d;
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<ll>> por(N, vector<ll>(2));
    vector<int> nums;
    REP(i, N){
        cin >> por[i][0] >> por[i][1];
        nums.push_back(i);
    }

    double ans = 0, num = 0;
    do {
        num++;
        REP(i, N-1){
            ans += dist(por[nums[i]][0], por[nums[i+1]][0], por[nums[i]][1], por[nums[i+1]][1]);
        }
    } while (next_permutation(nums.begin(), nums.end()));
    ans = ans/num;
    cout << fixed << setprecision(10) << ans << endl;
}