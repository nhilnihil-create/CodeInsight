#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int M = 82;
ll m,sum = 1000;
ll a[M];
priority_queue <int,vector <int>, greater <int> > q;

template<typename T>
inline void read(T &x){
    x = 0; char ch = getchar(); int f = 1;
    for(;ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
    x *= f;
}

int main(){
    read(m);
    for(int i = 1;i <= m; i++) read(a[i]);
    for(ll i = 1,x;i <= m - 1; i++){
        x = 0;
        if(a[i] < a[i + 1]) x = sum / a[i];
        sum += (a[i + 1] - a[i]) * x;
    }
    printf("%lld\n",sum);
    return 0;
}
/*
7
100 130 130 130 115 115 150

1685
*/