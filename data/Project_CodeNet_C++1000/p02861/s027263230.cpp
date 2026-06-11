#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int kaij(int n) {
    if(n == 1) {
        return 1;
    }
    return n*kaij(n - 1);
}

int main() {
    int N = 0;
    cin >> N;
    vector<int> x(N,0);
    vector<int> y(N,0);
    for(int i = 0; i < N; i++) {
        cin >> x.at(i);
        cin >> y.at(i);
    }
    double sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N && j != i; j++) {
            sum += pow(pow(x.at(i) - x.at(j),2) + pow(y.at(i) - y.at(j),2),0.5);
        }
    }
    cout << fixed << setprecision(10) << sum*2/N << endl;

    return 0;
}

//N*(N - 1)    N!*(N - 1)