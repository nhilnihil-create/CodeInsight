#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    int count;
    double score[1000];

    while (true) {
        cin >> count;
        if (count == 0) break;

        double sum = 0;
        for (int i = 0; i < count; i++) {
            cin >> score[i];
            sum += score[i];
        }

        double average = sum / count;
        double sum2 = 0;
        for (int i = 0; i < count; i++) {
            sum2 += pow(score[i] - average, 2);
        }

        printf("%lf\n", sqrt(sum2 / count));
    }
}