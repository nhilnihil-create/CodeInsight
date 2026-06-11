#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) { // 0-index
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        x.at(i) = tmp1; y.at(i) = tmp2;
    }
    vector<int> numbers;
    rep(i, n) numbers.push_back(i);  // 0-index

    double sum = 0;
    double numOfPertterns = 0;
    do {
        for (int i = 0; i < n - 1; i++) {
            int pre = numbers.at(i); int lat = numbers.at(i+1);
            double hoge = sqrt(pow((x.at(pre) - x.at(lat)), 2) + pow((y.at(pre) - y.at(lat)), 2));
            sum += hoge;
        }
        numOfPertterns++;
    } while (next_permutation(numbers.begin(), numbers.end()));

    double ans = sum / numOfPertterns;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
