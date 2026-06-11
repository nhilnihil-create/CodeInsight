#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)
#define PI (3.14159265358979323846)
using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

int N;
vector<pair<Int,Int>> XY;

double solve(void) {
    double ans = 0;
    double pi = acos(-1.0);
    for(int theta = 0;theta <= 360*2;theta++) {
        Int X = 0;
        Int Y = 0;
        for(int i = 0;i < N;i++) {
            double xcos = cos(theta*pi/360);
            double ysin = sin(theta*pi/360);
            if(xcos*XY[i].first+ysin*XY[i].second > 0) {
                X += XY[i].first;
                Y += XY[i].second;
            }
        }
        ans = max(ans, sqrt(X*X+Y*Y));
    }

    return ans;
}

int main(void) {
    cin>>N;

    for(int i= 0;i < N;i++) {
        double x,y;
        cin>>x>>y;
        XY.push_back({x,y});
    }

    cout<<fixed<<setprecision(18);
    cout<<solve()<<endl;

    return 0;
}



