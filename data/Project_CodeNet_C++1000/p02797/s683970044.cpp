#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    for (int i = 1; i <= k; i++)cout << s << " ";
    for (int i = k + 1; i <= n; i++)cout << (s == 1e9 ? s - 1 : s + 1) << " \n"[i == n];
    return 0;
}