/*
将这n个二元组看做n个向量。
移动方式遵循平行四边形定则。
所以两个向量夹角越小，相加形成的和向量模长就越大。
所以将这些向量按照极角排序。
选择的向量肯定是一个区间。
枚举左右端点，求最大值即可。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e2+5;

struct Point{
        int x,y;
}p[MAXN];

bool cmp(Point a,Point b) {
        return atan2(a.y,a.x) < atan2(b.y, b.x);
}

int nx[MAXN];//让它循环
int main() {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)   cin>>p[i].x>>p[i].y;
        for(int i=1;i<=n;++i)    nx[i] = i+1; nx[n] = 1;
        sort(p+1,p+n+1,cmp);
        ll  ans=0;
        for(int i=1;i<=n;++i) {
                ll x = p[i].x, y = p[i].y;
                ans = max(ans, x * x + y * y);
                for(int j=nx[i];j!=i;j = nx[j]) {
                        x += p[j].x;
                        y += p[j].y;
                        ans = max(ans, x * x + y * y);
                }
        }
        printf("%.10lf\n",sqrt(ans));
        return 0;
}


