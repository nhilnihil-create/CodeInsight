#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<ll> l(N,0), r(N,0);

    for(int i = 0; i < N; i++){
        if(i+A[i] < N) l[i + A[i]]++;
        if(i-A[i] > 0) r[i - A[i]]++;
    }

    ll cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += l[i] * r[i];
    }

    cout << cnt << endl;

    return 0;
}
