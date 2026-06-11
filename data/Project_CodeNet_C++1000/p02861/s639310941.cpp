#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double N;
    cin >> N;
    vector<vector<double>> p(N, vector<double>(2));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            cin >> p.at(i).at(j);
        }
    }
    sort(p.begin(), p.end());
    double dis = 0;
    int div = 0;
    do{
        for(int i = 1; i < N; i++){
            double x = pow(p.at(i).at(0) - p.at(i-1).at(0),2);
            double y = pow(p.at(i).at(1) - p.at(i-1).at(1),2);
            dis += pow(x + y, 0.5);
        }
        div++;
    }while(next_permutation(p.begin(), p.end()));
    double ans = dis / div;
    cout << fixed << setprecision(10) << ans << endl;
}