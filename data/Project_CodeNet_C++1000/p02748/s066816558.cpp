#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

const double PI=acos(-1);

int main(){
    int a, b, m;
    cin >> a >> b >> m;

    vector<int> aa(a), bb(b);
    int am = 999999, bm = 999999;
    for(int i = 0; i < a; i++){
        cin >> aa[i];
        am = min(am, aa[i]);
    }
    for(int i = 0; i < b; i++){
        cin >> bb[i];
        bm = min(bm, bb[i]);
    }
    int mi = am + bm;
    for(int i = 0; i < m; i++){
        int xx, yy, c;
        cin >> xx >> yy >> c;
        mi = min(mi, aa[xx-1]+bb[yy-1]-c);
    }

    cout << mi << endl;
    return 0;
}