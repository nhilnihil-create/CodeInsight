#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
#include<functional>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <math.h>
#define ll long long
#define PI 3.14159265358979323846
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
using namespace std;

double deg2rad(double degree)
{
    return degree * PI / 180.0;
}


int main() {
    string T;
    cin >> T;
    rep(i, T.size()) {
        if (T[i] == '?') {
            T[i] = 'D';
            
        }
    }
    cout << T << endl;
    return 0;

}
