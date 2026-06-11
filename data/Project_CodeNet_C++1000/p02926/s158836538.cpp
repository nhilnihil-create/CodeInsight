//@Author: wxyww
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<ctime>
#include<cmath>
#include<map>
#include<string>
using namespace std;
typedef long long ll;
#define pi pair<double,double>
const int N = 110;
ll read() {
    ll x = 0,f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0',c = getchar();}
    return x * f;
}
pi a[N];
bool cmp(const pi &A,const pi &B) {
    return atan2(A.second , A.first) > atan2(B.second , B.first);
}
int main() {
    int n = read();
    for(int i = 0;i < n;++i) a[i].first = read(),a[i].second = read();
    sort(a,a + n,cmp);
    double ans = 0;
    for(int i = 0;i < n;++i) {
        double X = a[i].first,Y = a[i].second;
        ans = max(ans,X * X + Y * Y);
        for(int j = (i + 1) % n;j != i;j = (j + 1) % n) {
            X += a[j].first,Y += a[j].second;
            ans = max(ans,X * X + Y * Y);
        }
    }
    printf("%.10lf",sqrt(ans));
    return 0;
}
