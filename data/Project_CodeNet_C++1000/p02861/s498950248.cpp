#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<limits.h>
#include <iomanip> 
using namespace std;


int N;
double x[10], y[10];
double distances[10][10];
double totaldistance = 0;
int main(){
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            distances[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            totaldistance += distances[i][j];
        }
    }
    cout << std::fixed << std::setprecision(15) << totaldistance / N << endl;
    return 0;
}
