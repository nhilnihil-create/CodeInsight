#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main() {
    int A, B, M, i, j, min, price;
    cin >> A >> B >> M;
    vector<int> fr(A);
    vector<int> mr(B);
    vector<vector<int>> discount(M, vector<int>(3));
    for (i = 0; i < A; i++) cin >> fr.at(i);
    for (i = 0; i < B; i++) cin >> mr.at(i);
    for (i = 0; i < M; i++) {
        for(j = 0; j < 3; j++) {
            cin >> discount.at(i).at(j);
        }
    }
    
    for (i = 0; i < M; i++) {
        price = fr.at(discount.at(i).at(0) - 1) + mr.at(discount.at(i).at(1) - 1) - discount.at(i).at(2);
        if (i == 0) min = price;
        else if (price < min) min = price;
    }
    sort(fr.begin(), fr.end());
    sort(mr.begin(), mr.end());
    price = fr.at(0) + mr.at(0);
    if (price < min) min = price;
    cout << min << endl;
}