#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

double dxy(vector<int> &x, vector<int> &y, int p){
    long long sum=0;
    for(int i=0; i<x.size(); ++i){
        sum += pow(abs(x[i]-y[i]),p);
    }
    return (pow(sum,1.0/p));
}
double dmax(vector<int> &x, vector<int> &y){
    int d_max=0;
    for(int i=0; i<x.size(); ++i){
        d_max = max(d_max,abs(x[i]-y[i]));
    }
    return d_max;
}


int main()
{

    int n;
    cin >> n;
    vector<int> x(n,0);
    vector<int> y(n,0);

    for(auto&& a: x){
        cin >> a;
    }

    for(auto&& a: y){
        cin >> a;
    }
    cout << fixed;
    cout << dxy( x, y, 1) << endl;
    cout << dxy( x, y, 2) << endl;
    cout << dxy( x, y, 3) << endl;
    cout << dmax( x, y) << endl;
    return 0;
}
