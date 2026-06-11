#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;

int main(){
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        double sum_1 = 0, sum_2 = 0;
        for(int i = 0; i < n; i++){
            double a; cin >> a;
            sum_1 += a; sum_2 += a * a;
        }
        double st_dev = sqrt(sum_2 / n - pow(sum_1 / n, 2));
        printf("%.10f\n", st_dev);
    }
}
