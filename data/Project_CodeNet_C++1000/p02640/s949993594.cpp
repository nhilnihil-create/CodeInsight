#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;
using posteriority_queue = priority_queue<int, vi, greater<int>>;


int main() {
    int X; cin >> X;
    int Y; cin >> Y;

    for (int i = 0; i <= X; i++) {
        int tmp;
        tmp = 2 * i + 4 * (X - i);
        if (tmp == Y) {
            cout << "Yes";
            break;
        } else if (i == X) {
            cout << "No";
        }
    }
}
