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
    i64 n, m;
    scanf("%lld%lld", &n, &m);
    priority_queue<i64> p;
    for(int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        p.push(x);
    }
    while(m--) {
        i64 x = p.top();
        p.pop();
        p.push(x/2);
    }
    i64 sum = 0;
    while(p.size()) {
        sum += p.top();
        p.pop();
    }
    printf("%lld\n", sum);
}
