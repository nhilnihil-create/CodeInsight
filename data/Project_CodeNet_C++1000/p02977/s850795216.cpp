#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

void print_edge(int x, int y) {
    cout << x << " " << y << endl;
}

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    {
        int m = 1;
        while(m < n) m <<= 1;
        if(n <= 2 || n == m) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;

    print_edge(1, 2);
    print_edge(2, 3);
    print_edge(3, n+1);
    print_edge(n+1, n+2);
    print_edge(n+2, n+3);

    for(int i=4;i+1<=n;i+=2) {
        print_edge(i, i+1);
        print_edge(i+1, n+1);
        print_edge(n+1, n+i);
        print_edge(n+i, n+i+1);
    }

    if(n % 2 == 0) {
        for(int i=3;i<n;i+=2) {
            if(n & (i ^ 1)) {
                int a = i ^ 1;
                int b = n ^ a;
                print_edge(n, i);
                print_edge(n+b, 2*n);
                break;
            }
        }
    }

}
