#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    double a, b, c ,d, ans;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    printf("%.15f\n", sqrt((a-c)*(a-c)+(b-d)*(b-d)));
    return 0;
}

