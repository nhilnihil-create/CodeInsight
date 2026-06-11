#include<iostream>
#include<cmath>

using namespace std;

int main () {

    int n;          // 学生の人数
    int s[1000];    // 得点, Score

    double m;       // 得点の平均

    double a2;      // 分散 a^2
    double a;       // 標準偏差 a

    while (1) {

        cin >> n;
        if (n == 0) {
            break;
        }

        m = 0;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            m += s[i];
        }

        m /= n;

        a2 = 0;

        for (int i = 0; i < n; i++) {
            a2 += pow(s[i] - m, 2) / n;
        }

        a = sqrt(a2);

        cout << a << endl;

    }    

    return 0;
}
