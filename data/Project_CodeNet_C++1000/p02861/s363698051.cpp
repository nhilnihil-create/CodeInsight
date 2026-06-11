#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct xy {
    double x;
    double y;
};

int main() {
    int n;
    cin >> n;
    vector<xy> T(n);
    rep(i, n) cin >> T[i].x >> T[i].y;


    vector<int> one_case;
    for (int i = 0; i < n; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }
    double tot = 0.0;
    do {
        double tmp = 0.0;
        for (int i = 0; i < n-1; i++) {
            tmp += sqrt((T[one_case[i]].x -T[one_case[i+1]].x)*(T[one_case[i]].x -T[one_case[i+1]].x)
                      + (T[one_case[i]].y -T[one_case[i+1]].y)*(T[one_case[i]].y -T[one_case[i+1]].y));
        }
        tot += tmp;
    } while (next_permutation(one_case.begin(), one_case.end()));

    int nn = 1;
    for (int i = 1; i <= n; i++) nn *= i;

    printf("%.10f\n", (double)tot/nn);
    
    return 0;
}