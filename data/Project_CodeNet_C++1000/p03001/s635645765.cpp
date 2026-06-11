#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    double w, h;
    cin >> w >> h;
    ll x, y;
    cin >> x >> y;
    double ans_area = w * h / 2;
    printf("%.10lf ", ans_area);
    if(w / 2 == x && h / 2 == y) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}