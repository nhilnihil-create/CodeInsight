#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double p1 = 0, p2 = 0, p3 = 0, p00 = -1;
    cin >> n;
    vector<int> xi;
    vector<int> yi;
    int i = n;
    int temp;
    while (i --> 0) {
        cin >> temp;
        xi.push_back(temp);
    }
    while (n --> 0) {
        cin >> temp;
        yi.push_back(temp);
    }
    for (auto i1 = xi.begin(), i2 = yi.begin(); i1 != xi.end() && i2 != yi.end(); ++i1, ++i2) {
        p1 += abs(*i1 - *i2);
        p2 += pow(*i1 - *i2, 2);
        p3 += pow(abs(*i1 - *i2), 3);
        p00 = max(p00, (double)abs(*i1 - *i2));
    }
    p2 = pow(p2, 1/(double)2);
    p3 = pow(p3, 1/(double)3);

    printf("%.6f\n", p1);
    printf("%.6f\n", p2);
    printf("%.6f\n", p3);
    printf("%.6f\n", p00);
}
