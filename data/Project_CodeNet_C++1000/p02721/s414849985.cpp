#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<int> left(n+1), right(n+1);
    int rev = -c-10;
    rep(i,n) {
        if (s[i]=='o' && rev+c < i) {
            left[i+1] = left[i]+1;
            rev = i;
        } else {
            left[i+1] = left[i];
        }
    }
    rev = n+c+10;
    repr(i,n-1) {
        if (s[i]=='o' && rev-c > i) {
            right[i] = right[i+1]+1;
            rev = i;
        } else {
            right[i] = right[i+1];
        }
    }

    rep(i,n) {
        if (left[i]+right[i+1] < k) {
            cout << i+1 << endl;
        }
    }
    return 0;
}