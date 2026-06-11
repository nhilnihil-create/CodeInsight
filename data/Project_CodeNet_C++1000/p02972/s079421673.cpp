#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;
    cin >> N;
    vector<ll> a(N+1);
    vector<ll> h(N+1);
    vector<ll> M;

    REP(i,N){ cin >> a[i+1];};

    for(int i = N; i > 0; i-- ){
       ll j = i+i;
       ll count = 0;
       while( j <= N ){
            count = (count + h[j])%2;
            j+=i;
       }
       h[i] = (count + a[i])%2;
       if( h[i] == 1 ){
            M.push_back(i);
       }
    }

    cout << M.size() << endl;
    REP(i, M.size()){
        cout << M[i] << " ";
    }
    cout << endl;
}
