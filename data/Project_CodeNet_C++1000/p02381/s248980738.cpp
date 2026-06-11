#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int n, s;
    double mean, sd, sum = 0;
    vector<int> ss;
    while (1) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> s;
            sum += s;
            ss.push_back(s);
        }
        mean = sum / n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pow((ss[i] - mean), 2.0);
        }
        sd = sqrt(sum / n);
        printf("%.5f\n", sd);
        sum = 0;
        vector<int>().swap(ss);  // Force free
    }
    return 0;
}