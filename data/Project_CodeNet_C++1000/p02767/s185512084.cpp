#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int xi;
    vector<int> X(n);
    float S = 0.;
    for (int i=0; i<n; i++){
        cin >> X[i];
        S += X[i];
    }
    int mu = round(S / n);
    int distance = 0;
    for (int i=0; i<n; i++) {
        distance += pow(X[i] - mu, 2);
    }
    cout << distance << endl;

}