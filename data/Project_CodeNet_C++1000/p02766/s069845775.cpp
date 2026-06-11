#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include<stack>
#include<string>
#include<algorithm> 
#include <set>
#include<list>
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
using namespace std;
int main() {
    long long int N, K; cin >> N >> K;
    int ans = 0;
    while (1) {
        ans++;
        N /= K;
        if (N == 0)break;
    }
    cout << ans << endl;
    return 0;
}