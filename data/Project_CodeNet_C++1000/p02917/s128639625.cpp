#include <iostream> 
#include <cstdio> 
#include <cstdlib>  
#include <algorithm> 
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long ll;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    int N;
    cin >> N;
    vector<int> B(N, 1e9);
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    int ans = B[0];
    for (int i = 1; i < N; i++) {
        ans += min(B[i], B[i - 1]);
    }
    cout << ans << endl;
}
