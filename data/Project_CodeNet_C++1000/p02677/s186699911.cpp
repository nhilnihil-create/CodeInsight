//g++  7.4.0

#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    std::string s;
    cin >> s;

    double hourhand = 360.0 * ((double)h/12.0) + 30.0 * ((double)m/60.0);
    double minutehand = 360.0 * ((double)m/60.0);
    double delta = std::abs(minutehand - hourhand);
    //cout << hourhand << ", " << minutehand << ", " << delta << endl;
    
    // 余弦定理
    double ans = std::sqrt(a*a + b*b - 2.0 * a * b * cos(delta * M_PI/180.0));
    printf("%.12lf\n", ans);
    
    return 0;
}

