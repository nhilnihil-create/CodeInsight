#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

struct Point{
    int x;
    int y;
};


int main(){
    int N;
    cin >> N;
    int xy[N][2];
    int zw[N][2];

    for (int i = 0; i < N; ++i){
        cin >> xy[i][0] >> xy[i][1];
        zw[i][0] = xy[i][0] + xy[i][1];
        zw[i][1] = xy[i][0] - xy[i][1];
    }

    int z_MAX = zw[0][0], w_MAX = zw[0][1],
        z_min = zw[0][0], w_min = zw[0][1];

    for (int i = 1; i < N; ++i){
        z_MAX = max(z_MAX, zw[i][0]);
        z_min = min(z_min, zw[i][0]);
        w_MAX = max(w_MAX, zw[i][1]);
        w_min = min(w_min, zw[i][1]);
    }

    cout << max(z_MAX - z_min, w_MAX - w_min) << endl;

}

