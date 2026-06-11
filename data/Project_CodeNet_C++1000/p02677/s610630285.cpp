#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int a[N];
set<int>v;
const double PI=acos(-1.0);

int main()
{
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double th = (60*h+m)/720*2*PI;
    double tm = 2*PI*m/60;
    double ans = a*a + b*b - 2*a*b*cos(th-tm);
    ans = sqrt(ans);
    printf("%.10f\n", ans);

    return 0;
}

