#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;


int main() {
    int X, N;
    Pint ans = make_pair(999999, 99999);
    cin >> X >> N;
    set<int> A;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        A.insert(a);
    }
    for (int i = -101; i <= 101; i++){
        if (A.count(i)){
            continue;
        }
        int t = abs(X - i);
        if (t < ans.first){
            ans.first = t;
            ans.second = i;
        }
    }
    cout << ans.second << endl;
}