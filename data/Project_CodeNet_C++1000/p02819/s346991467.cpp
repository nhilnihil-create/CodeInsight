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
typedef pair<int, int> P;

vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > SIZE(IsPrime)){
        IsPrime.resize(max+1, true);
    }
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(size_t i = 2; i <= sqrt(max); i++){
        if(IsPrime[i]){
            for(size_t j = 2; i*j <= max; j++){
                IsPrime[i*j] = false;
            }
        }
    }
}

int main() {
    int X;
    cin >> X;

    sieve(1e+5+10);

    int i = X;
    while(1){
        if (IsPrime[i]) break;
        i++;
    }
    cout << i << endl;
}