#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long int LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
#define NMAX 100005*2


ll tab[NMAX];
ll tabdiff[NMAX];
ll tabsum[NMAX];
int main(){
    int n;
    ll count=0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>tab[i];
        if(i-tab[i] >=0){
            tabdiff[i-tab[i]]++;
        }
        if(i+tab[i] < n){
            tabsum[i+tab[i]]++;
        }
    }

    for (int i = 0; i < NMAX; ++i)
    {
        count += tabsum[i] * tabdiff[i];
    }

    cout<<count<<endl;
    return 0;
}
