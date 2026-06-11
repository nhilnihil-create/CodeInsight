#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
using ll = long long int;

const double PI = 3.1415926535897932384626433;

int main(){
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++)cin >> x[i] >> y[i];

    double maxlength = 0.0;
    for(int i = 0; i < 360; i++){
        double xd = cos((double)i/180*PI);
        double yd = sin((double)i/180*PI);
        ll nowx = 0;
        ll nowy = 0;
        for(int j = 0; j < n; j++){
            if (xd*x[j] + yd*y[j] >= 0){
                nowx += x[j];
                nowy += y[j];
            }
        }

        double length = sqrt((double)(nowx*nowx + nowy*nowy));
        maxlength = max(maxlength, length);
    }

    cout << fixed << setprecision(15) << maxlength << endl;
    return 0;
}