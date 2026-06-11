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
string s;

int main() {
    ll A, V, B, W;
    ll T;
    cin >> A >> V >> B >> W >> T;
    if (A == B)puts("YES");
    else if (0 < (V - W) && (V - W) * T >= abs(B - A))puts("YES");
    else puts("NO");
    return 0;
}