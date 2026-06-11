#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

vector<int> seg;
int s;
void seg_init(int n) {
    s = 1;
    while(s < n) s*= 2;
    seg.resize(2*s-1, INT_MAX);
    rp(i, 0, n) {
        seg.at(s-1+i) = i+1;
    }
    for(int i = s-2; i >= 0; i--) {
        seg.at(i) = min(seg.at(i*2+1), seg.at(i*2+2));
    }
}

void seg_insert(int a, int b) {
    seg.at(s-1+a) = b;
    int p = s-1+a;
    while(p != 0) {
        p = (p+1)/2 -1;
        seg.at(p) = min(seg.at(p*2+1), seg.at(p*2+2));
    }
}

int seg_find(int x, int y, int a=0, int b=s, int k=0) {
    if(b <= x || y <= a) return INT_MAX;
    if(x <= a && b <= y) return seg.at(k);
    else{
        int left = seg_find(x, y, a, (a+b)/2, 2*k+1);
        int right = seg_find(x, y, (a+b)/2, b, 2*k+2);
        return min(left, right);
    }
}

int main() {
    int n, m; cin >> n >> m;
    seg_init(m);
    vector<pair<int, int>> work;
    rp(i, 0, n) {
        int a, b;
        scanf("%d%d", &a, &b);
        work.emplace_back(-b, a);
    }
    // printf("s = %d\n", s);
    sort(work.begin(), work.end());
    int res = 0;
    rp(i, 0, n) {
        int reward = -work.at(i).first;
        int day = work.at(i).second;
        // printf("reward = %d day = %d", reward, day);
        int c = seg_find(day-1, m);
        // printf("c = %d\n", c);
        if(c == INT_MAX) continue;
        res += reward;
        seg_insert(c-1, INT_MAX);
    }
    cout << res << endl; return 0;
}