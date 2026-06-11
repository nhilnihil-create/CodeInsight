#include <bits/stdc++.h>
using namespace std;

double func(int x1, int y1, int x2, int y2){
    int res = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    return sqrt(res);
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> town(n);
    double sum;
    int z = 1;
    for(int i = 1; i <= n; i++){
        z *= i;
    }//n!を求めておく

    for(int i = 0; i < n; i++){
        cin >> x.at(i) >> y.at(i);
    }

    
    for(int i = 0; i < n; i++){
        town.at(i) = i;
    }
    double tmp;
    do{
        tmp = 0;
        for(int i = 0; i < n - 1; i++){
            tmp += func(x.at(town.at(i)), y.at(town.at(i)), x.at(town.at(i + 1)), y.at(town.at(i + 1)));
            //cout << tmp << endl;
            }
        sum += tmp;
    }while(next_permutation(town.begin(), town.end()));

    sum /= (double)z;
    //cout << sum << setprecision(10) << endl;
    printf("%.10f", sum);
}
