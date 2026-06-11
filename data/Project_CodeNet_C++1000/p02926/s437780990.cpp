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
    return 7-acos(p.x/sqrt(1LL*p.x*p.x + 1LL*p.y*p.y));
}
long long sqr(long long num){
    return num*num;
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
    sort(vs.begin() ,vs.end() ,[](point p1 ,point p2){
        return ang(p1) < ang(p2);
    });
    vs.insert(vs.end() ,vs.begin() ,vs.end());

    long long ans = 0LL ,sx = 0LL ,sy = 0LL;
    for(int i=0,j=0; i<n; i++){
        while(j-i+1<=n && j < vs.size() && sqr(sx+vs[j].x)+sqr(sy+vs[j].y) > sqr(sx)+sqr(sy))
            sx += vs[j].x ,sy += vs[j].y ,j++;
        ans = max(ans ,sqr(sx)+sqr(sy));
        sx -= vs[i].x ,sy -= vs[i].y;
    }

    printf("%.10f\n",sqrt(ans));
}
