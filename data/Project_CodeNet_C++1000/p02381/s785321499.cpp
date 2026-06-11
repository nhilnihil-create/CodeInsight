#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int n; // 学生の数

    while(cin >> n){
        if(0 == n){
            break;
        }
        // cout << n << endl;

        int s[n]; // 得点
        int sum = 0; // 合計
        double m = 0; // 平均値

        for(int i = 0; i < n; i++){
            cin >> s[i];
            // cout << s[i] << " ";
            sum += s[i];
        }
        // cout << endl;
        // cout << sum << endl;
        m = (double)sum / (double)n;
        // cout << m << endl; 

        double aaa = 0;
        for(int i = 0; i < n; i++){
            // cout << s[i] - m << endl;
            aaa += pow(s[i] - m, 2);
            // cout << aaa << endl;
        }
        aaa = sqrt(aaa / n);
        // cout << aaa << endl;
        printf("%lf\n", aaa);
    }

    return 0;
}
