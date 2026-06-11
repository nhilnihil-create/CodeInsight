#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; i++)
#define INF (1<<30)

typedef long long ll;

using namespace std;

double Euclid_distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2, 2));
}

void solve(){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout.precision(10);
    cout << Euclid_distance(x1, y1, x2, y2) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
