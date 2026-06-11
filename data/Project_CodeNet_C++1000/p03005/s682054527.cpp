#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N, K;

int main()
{
    cin >> N >> K;
    N -= K;
    cout << (K == 1 ? 0 : N) << endl;
}