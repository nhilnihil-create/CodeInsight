#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int n; // 整数

    while(cin >> n){
        int x[n]; // n次元のベクトル
        int y[n]; // n次元のベクトル

        for(int i = 0; i < n; i++){
            cin >> x[i];
            // cout << x[i] << " ";
        }
        // cout << endl;

        for(int i = 0; i < n; i++){
            cin >> y[i];
            // cout << y[i] << " ";
        }
        // cout << endl;

        double a1 = 0;
        for(int i = 0; i < n; i++){
            // cout << (x[i] - y[i]) << endl;
            a1 += fabs(x[i] - y[i]);
        }

        double a2 = 0;
        for(int i = 0; i < n; i++){
            a2 += pow(fabs(x[i] - y[i]), 2);
        }
        a2 = sqrt(a2);

        double a3 = 0;
        for(int i = 0; i < n; i++){
            a3 += pow(fabs(x[i] - y[i]), 3);
        }
        // cout << a3 << endl;
        a3 = pow(a3, 1.0 / 3.0);

        double a4 = 0;
        for(int i = 0; i < n; i++){
            if(a4 < fabs(x[i] - y[i])){
                a4 = fabs(x[i] - y[i]);
            }
        }

        printf("%lf\n", a1);
        printf("%lf\n", a2);
        printf("%lf\n", a3);
        printf("%lf\n", a4);
    }

    return 0;
}
