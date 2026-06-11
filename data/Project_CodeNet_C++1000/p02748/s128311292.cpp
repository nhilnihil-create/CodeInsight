#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1000000000; //10^9

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    for (int i = 0; i < A; i++) cin >> a.at(i);
    for (int i = 0; i < B; i++) cin >> b.at(i);
    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());
    int ans = minA + minB;
    for(int i = 0; i < M; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        ans = min(ans, a.at(x) + b.at(y) - c);
    }
    cout << ans << endl;
}
