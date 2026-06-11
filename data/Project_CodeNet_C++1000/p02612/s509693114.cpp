#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    ll N;
    cin >> N;
    int i = 1000;
    for (i; i < N; i += 1000);
    cout << i - N << endl;
    return 0;
}