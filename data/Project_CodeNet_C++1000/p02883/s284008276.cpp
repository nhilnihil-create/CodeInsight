#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    ll N, K;
    cin >> N >> K;

    int A[N], F[N];
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> F[i];

    sort(A, A+N);
    sort(F, F+N, greater<int>());

    ll l = -1;
    ll r = 1000000000005;
    while(l+1<r){
        ll mid = (l+r)/2;
        ll total = 0;
        for(int i=0; i<N; i++){
            if((ll)A[i]*F[i]>mid) total = total + (ll)A[i] - mid/F[i];
        }
        if(total > K) l = mid;
        else r = mid;
    }
    cout << r << endl;

    return 0;
}
