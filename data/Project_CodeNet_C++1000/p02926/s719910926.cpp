#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

struct vec
{
    int64_t x,y;

    int quatr() const
    {
        if (x>0 && y>=0) return 0;
        else if (x<=0 && y>0) return 1;
        else if (x<0 && y<=0) return 2;
        else if (x>=0 && y<0) return 3;
        else return 666;
    }

    bool operator<(const vec& v) const
    {
        int l = quatr();
        int r = v.quatr();
        if (l == r) return x*v.y-y*v.x > 0;
        else return l < r;
    }
    vec operator+(const vec& v) const
    {
        return {x+v.x, y+v.y};
    }
    vec& operator+=(const vec& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    int64_t len() const
    {
        return x*x + y*y;
    }
} V[100];

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int64_t result = 0;
    for (int i=0;i<n;++i) std::cin >> V[i].x >> V[i].y;
    std::sort(V, V+n);

    for (int s=0;s<n;++s)
    {
        vec v = {0, 0};
        for (int l=0;l<n;++l)
        {
            v += V[(s+l)%n];
            result = std::max(result, v.len());
        }
    }

    std::cout << std::setprecision(20) << std::fixed << sqrtl(result);
    return 0;
}