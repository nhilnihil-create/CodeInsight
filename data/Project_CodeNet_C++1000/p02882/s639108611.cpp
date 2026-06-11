#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

auto f(double t, double a, double b) {
    if (tan(t) <= b / a) {
        return a*b - a*(a*tan(t))/2;
    }
    else {
        return b*(b/tan(t))/2;
    }
}

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;
    double left = 0, right = M_PI/2;
    for (int iter = 0; iter < 100; iter++) {
        double theta = (left + right) / 2;
        if (f(theta, a, b) >= x) {
            left = theta;
        }
        else {
            right = theta;
        }
    }
    cout << fixed << setprecision(10) << left*180/M_PI << endl;
}
