#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;





int main()
{
   
    double a, b;
    double h, m;
    cin >> a >> b;
    cin >> h >> m;
    

    double ax, ay;
    double bx, by;
    double g, f;
    if (h < 3) {
        g = 90 - 30 * h;
        g -= (m / 2);
    }
    else if (h < 6) {
        g = -30 * (h - 3);
        g -= (m / 2);
    }
    else if (h < 9) {
        g = -90 - 30 * (h - 6);
        g -= (m / 2);
    }
    else if (h < 12) {
        g = -180 - 30 * (h - 9);
        g -= (m / 2);
    }

    f = 90;
    f -= 6 * m;

 //   cout << g << " " << f << endl;
    g = g / 180 * M_PI;
    f = f / 180 * M_PI;
    ax = a * cos(g);
    ay = a * sin(g);

    bx = b * cos(f);
    by = b * sin(f);
    //cout << ax << " " << ay << " " << bx << " " << by << endl;

    cout << setprecision(20);
    double p;

    p = sqrt(abs(ax - bx) * abs(ax - bx) + abs(ay - by) * abs(ay - by));
   
    cout << p << endl;

    return 0;

}