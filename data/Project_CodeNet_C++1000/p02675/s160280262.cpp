#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N;

int main() {
    cin >> N;
    int z = N%10;
    vector<int> a = {2,4,5,7,9}, b = {0,1,6,8};
    if (z == 3) cout << "bon" << endl;
    else if (find(ALL(a), z)  != a.end() ) cout << "hon" << endl;
    else if (find(ALL(b), z)  != b.end() ) cout << "pon" << endl;
}
