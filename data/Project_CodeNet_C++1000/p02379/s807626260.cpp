#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
    double P1_x, P1_y, P2_x, P2_y, d;
    cin >> P1_x >> P1_y >> P2_x >> P2_y;
    d = sqrt(pow((P2_x-P1_x),2)+pow((P2_y-P1_y),2));
    printf("%f", d);
    return 0;
}
