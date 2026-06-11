#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>

int main() {
    int n;
    while (1){
        cin >> n;
        if (n == 0) break;
        double s[n], sum = 0, mean, std;
        for (int i = 0; i < n; i++){
            cin >> s[i];
            sum += s[i];
        }
        mean = sum / n;
        sum = 0;
        for (int i = 0; i < n; i++){
            sum += (s[i] - mean) * (s[i] - mean);
        }
        std = sqrt(sum / n);
        printf("%lf\n",std);
    }

    return 0;
}