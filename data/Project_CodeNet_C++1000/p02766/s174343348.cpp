#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    ll N; cin >> N;
    int K; cin >> K;
    int count = 0;

    for(int i=0; N-pow(K,i)>=0; i++) count++;
    cout << count << endl;
}