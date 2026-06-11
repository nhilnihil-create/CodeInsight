#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
    int n , d;
    cin >> n >> d;
    long long int x[n], y[n];
    double k;
    int sum = 0;
    rep(i,n){
        cin >> x[i] >> y[i];
        k = sqrt(x[i]*x[i] + y[i]*y[i]);
        if(k <= d)sum++;
    }
    cout << sum << endl;
}
