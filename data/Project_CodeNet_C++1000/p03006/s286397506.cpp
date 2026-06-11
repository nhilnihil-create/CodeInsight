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
    ll N;
    cin >> N;
    if(N == 1){
        printf("1\n");
        return 0;
    }

    vector<ll> x(N), y(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<llll> sa;
    ll a, b;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            a = x[i] - x[j];
            b = y[i] - y[j];
            if(a < 0){
                a = -a;
                b = -b;
            }
            else if(a == 0){
                b = abs(b);
            }
            sa.push_back(make_pair(a, b));
        }
    }

    sort(ALL(sa));

    ll S = sa.size();
    ll k = 1;
    ll tmp = 1;
    a = sa[0].first; b = sa[0].second;
    for (int i = 1; i < S; i++) {
        if(a == sa[i].first && b == sa[i].second){
            tmp++;
        }
        else{
            k = max(tmp, k);
            tmp = 1;
            a = sa[i].first; b = sa[i].second;
        }
    }
    k = max(tmp, k);

    printf("%lld\n", N - k);

}