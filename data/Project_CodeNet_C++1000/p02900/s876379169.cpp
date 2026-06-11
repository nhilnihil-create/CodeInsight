#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; __print(x);


int main()
{
    i64 a, b;
    scanf("%lld%lld", &a, &b);
    i64 g = __gcd(a, b);
    i64 sq = sqrt(g);
    int cnt = 0;
    for(i64 i = 2; i <= sq; i++){
        if(g%i==0) {
            while(g%i == 0) g/=i;
            cnt++;
        }
    }
    cnt++;
    if(g > 1) cnt++;
    printf("%d\n", cnt);
}
