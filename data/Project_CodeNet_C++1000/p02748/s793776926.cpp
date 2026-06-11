#include <bits/stdc++.h>
using namespace std;


int main(){

    int A, B, M;
    cin >> A >> B >> M;

    vector<int> a(A);
    vector<int> b(B);
    for (int i=0; i<A; i++) cin >> a.at(i);
    for (int i=0; i<B; i++) cin >> b.at(i);

    int min_a = 1e6;
    int min_b = 1e6;

    for (int i=0; i<A; i++){
        min_a = min(min_a, a.at(i));
    }
    for (int i=0; i<B; i++){
        min_b = min(min_b, b.at(i));
    }

    int min_price = min_a + min_b;

    int x, y, c, min_buf = 1e6;
    for (int i=0; i<M; i++){
        cin >> x >> y >> c;
        min_buf = a.at(x-1) + b.at(y-1) - c;
        min_price = min(min_buf, min_price);
    }

    cout << min_price << endl;
    return 0;
}