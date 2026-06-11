#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> abs_diff(const vector<int> &xs, const vector<int> &ys);
double minkov(const vector<int> &difs, int p);

int main(){
    int n;
    cin >> n;
    vector<int> xs(n, 0), ys(n, 0);
    for(auto &x : xs) cin >> x;
    for(auto &y : ys) cin >> y;
    vector<int> difs = abs_diff(xs, ys);
    cout << fixed << setprecision(6);
    cout << minkov(difs, 1) << endl;
    cout << minkov(difs, 2) << endl;
    cout << minkov(difs, 3) << endl;
    cout << *max_element(difs.begin(), difs.end()) << endl;

}

vector<int> abs_diff(const vector<int> &xs, const vector<int> &ys){
    vector<int> difs(xs.size(), 0);
    for(size_t i = 0; i != xs.size(); ++i) difs[i] = abs(xs[i] - ys[i]);
    return difs;
}


double minkov(const vector<int> &difs, int p){
    double sum = 0;
    for(auto dif : difs) sum += pow(dif, p);
    return pow(sum, 1.0 / p);
}