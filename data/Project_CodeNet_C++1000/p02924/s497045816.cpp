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
    i64 n;
    scanf("%lld", &n);
    printf("%lld\n", (n*n-n)/2);
}
