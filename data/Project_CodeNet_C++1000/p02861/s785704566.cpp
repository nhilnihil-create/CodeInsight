#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    int n = 0;
    cin >> n;
    vector<pair<int,pair<double,double>>> z(n);
    for(int i = 0;i < n;i++){
        int x = 0;
        int y = 0;
        cin >> x >> y;
        z[i].first = i;
        z[i].second.first = x;
        z[i].second.second = y;
    }
    double sum = 0;
    do{
        double tmpSum = 0;
        for(int i = 0;i < n - 1;i++){
            tmpSum += sqrt((z[i].second.first - z[i + 1].second.first) * (z[i].second.first - z[i + 1].second.first) + (z[i].second.second - z[i + 1].second.second) *  (z[i].second.second - z[i + 1].second.second));
        }
        //cout << tmpSum << endl;
        sum += tmpSum;
    }while(next_permutation(z.begin(),z.end()));
    double div = n;
    for(int i = n - 1;i >= 1;i--){
        div *= i;
    }
    cout << std::fixed << std::setprecision(7) << sum / div << endl;
    return 0;
}