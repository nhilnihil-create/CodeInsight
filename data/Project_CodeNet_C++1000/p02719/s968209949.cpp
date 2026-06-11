#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t N, K;
    cin >> N >> K;
    N %= K;
    cout << min(N, K-N) << endl;
    return 0;
}
