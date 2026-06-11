#include <cstdio>
#include <cmath>
#include <utility>

using namespace std;

using point=pair<double, double>;

int n;

void koch(int n, point &p1, point &p2)
{
    if(n){
        point s=make_pair((2*p1.first+p2.first)/3, (2*p1.second+p2.second)/3);
        point t=make_pair((p1.first+2*p2.first)/3, (p1.second+2*p2.second)/3);
        double xx=t.first-s.first, yy=t.second-s.second;
        point u=make_pair((xx-sqrt(3)*yy)/2+s.first, (sqrt(3)*xx+yy)/2+s.second);

        koch(n-1, p1, s);
        printf("%f %f\n", s.first, s.second);
        koch(n-1, s, u);
        printf("%f %f\n", u.first, u.second);
        koch(n-1, u, t);
        printf("%f %f\n", t.first, t.second);
        koch(n-1, t, p2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    point p1=make_pair(0, 0), p2=make_pair(100, 0);
    printf("%f %f\n", p1.first, p1.second);
    koch(n, p1, p2);
    printf("%f %f\n", p2.first, p2.second);
    return 0;
}