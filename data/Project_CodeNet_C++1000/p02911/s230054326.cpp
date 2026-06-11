#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int main(void) {
    ll N,K,Q; cin>>N>>K>>Q;
    ll ary[Q];
    ll ppl[N];
    
    for (int i = 0; i < Q; i++) cin >> ary[i];
    ll tmp = K-Q;

    for(int j = 0; j < N; j++) ppl[j] = tmp;

    for (int i = 0; i < Q; i++){
        ppl[ary[i] - 1]++;
    }
    for (int j = 0; j < N; j++){
        if (ppl[j] > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}