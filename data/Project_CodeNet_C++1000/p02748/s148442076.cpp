#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 1e9;
using namespace std;

int main(void) {
    int A,B,M;cin>>A>>B>>M;
    vector<int> a(A), b(B);
    int min_a = INF;
    int min_b = INF;
    for (int i = 0; i < A; i++) {
        cin>>a[i];
        if (min_a > a[i]) min_a = a[i];
    }
    for (int i = 0; i < B; i++) {
        cin>>b[i];
        if (min_b > b[i]) min_b = b[i];
    }
    int min_discount = INF;
    for (int i = 0; i < M; i++) {
        int x,y,c;
        cin>>x>>y>>c;
        int res = a.at(x - 1) + b.at(y - 1) - c;
        if (res < min_discount) min_discount = res;
    }
    cout << min(min_a + min_b, min_discount) << endl;
    return 0;
}