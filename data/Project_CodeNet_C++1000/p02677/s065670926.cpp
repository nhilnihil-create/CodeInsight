#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define PI acos(-1)
typedef long long ll;
using namespace std;
int main()
{
    Tayeb;
    int A,B,H,M;
    double h1,h2,m,distance=0;

    cin >> A >> B >> H >> M;
    h1=PI * (1.0/6) * H;
    h2=PI * (1.0/360) * M;
    m=PI * (1.0/30) * M;
    distance=A*A;
    distance+=B*B;
    distance-=2*A*B*cos(h1+h2-m);
    printf("%.20lf",sqrt(distance));

    return 0;

}