#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    int ans = 0;
    int m = inINF;

    for (int i = 0; i < N; i++) {
        if(P[i] <= m){
            ans++;
            m = P[i];
        }
    }
    printf("%d\n", ans);

}