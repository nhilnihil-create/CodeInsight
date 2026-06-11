#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int X, A;
    cin >> X >> A;
    cout << ((X < A) ? 0 : 10) << endl;
    return 0;
}