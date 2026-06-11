#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long INF = 1LL << 60;
ll MOD = 1e9+7;

int main() {
    double A,B,H,M; cin>>A>>B>>H>>M;
    double tyosin, tansin;
    tyosin = H / 12 + (M / 60 / 12);
    tansin = M / 60;

    double thita = min((abs(tyosin-tansin)*360),abs((abs(tyosin-tansin)*360 - 360)));
    double ans = sqrt(A*A+B*B - 2*A*B*cos(M_PI*(thita/180) ));
    
    printf("%.10lf", ans);
}