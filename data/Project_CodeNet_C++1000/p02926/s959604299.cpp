#include <bits/stdc++.h>
using namespace std;

#define point pair<int ,int>
#define x first
#define y second

int n;
vector <point> vs;

double ang(point p){
    if(p.x >= 0 && p.y >= 0 || p.x <= 0 && p.y >= 0)
        return acos(p.x/sqrt(1LL*p.x*p.x + 1LL*p.y*p.y));
    return 360-acos(p.x/sqrt(1LL*p.x*p.x + 1LL*p.y*p.y));
}
bool cmp(point p1 ,point p2){
    return ang(p1) < ang(p2);
}

int main()
{
    scanf("%d",&n);
    for(int a,b,i=0; i<n; i++){
        scanf("%d%d",&a,&b);
        if(a||b)
            vs.push_back({a ,b});
    }

    n = vs.size();
    sort(vs.begin() ,vs.end() ,cmp);
    vs.insert(vs.end() ,vs.begin() ,vs.end());

    long long ans = 0LL;
    for(int i=0; i<n; i++){
        long long sx = 0LL ,sy = 0LL;
        for(int j=i; j<i+n; j++){
            sx += vs[j].x ,sy += vs[j].y;
            ans = max(ans ,1LL*sx*sx + 1LL*sy*sy);
        }
    }

    printf("%.10f\n",sqrt(ans));
}
