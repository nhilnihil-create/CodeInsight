#include <bits/stdc++.h>
using namespace std;
int main() {
    int X,Y;
    cin >> X >> Y;
    vector<int> maney(205,0);
    maney.at(0) = 300000;
    maney.at(1) = 200000;
    maney.at(2) = 100000;
    if(X == 1 && Y == 1) {
        cout << maney.at(X - 1) + maney.at(Y - 1) + 400000;
    }else{
        cout << maney.at(X - 1) + maney.at(Y - 1);
    }
}
