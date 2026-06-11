#include <iostream>
#include <limits>

#define R3 (1.732050807568877293527446341505872366942805253810380628)

using namespace std;

void koch(double x1, double y1, double x2, double y2, int n)
{
    if(n--==0) return;
    double sx, sy, tx, ty, ux, uy;
    sx=(x1*2+x2)/3;
    sy=(y1*2+y2)/3;
    tx=(x1+x2*2)/3;
    ty=(y1+y2*2)/3;
    ux=(x1+x2)/2-(y2-y1)*R3/6;
    uy=(y1+y2)/2+(x2-x1)*R3/6;
    koch(x1, y1, sx, sy, n);
    cout<<sx<<' '<<sy<<'\n';
    koch(sx, sy, ux, uy, n);
    cout<<ux<<' '<<uy<<'\n';
    koch(ux, uy, tx, ty, n);
    cout<<tx<<' '<<ty<<'\n';
    koch(tx, ty, x2, y2, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout.setf(ios::fixed);
    cout.precision(8);
    cout<<"0 0\n";
    koch(0.0, 0.0, 100.0, 0, n);
    cout<<"100 0\n";
    return 0;
}