#include "bits/stdc++.h"
using namespace std;
#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
typedef long long ll;

const int INF = 1e9 + 7;
const long long LLINF = 1e18;

ll n;
bool isPrime[300001];
void get_prime(){
    isPrime[0]=isPrime[1]=false;
    REP(i, 2, 300001) isPrime[i]=true;
    for(int i=2; i*i<300001; i++){
        for(int j=2*i; j<300001; j+=i){
            isPrime[j]=false;
        }
    }
    return;
}
int main() {
    get_prime();

    while(cin>>n, n!=0){
        ll ans=0;
        REP(i, n+1, 2*n+1){
            if(isPrime[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
