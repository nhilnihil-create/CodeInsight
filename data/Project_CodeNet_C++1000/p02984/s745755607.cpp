#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << __LINE__ << " : [" << #x << "] = ["; __print(x)


int main()
{
    int n;
    scanf("%d", &n);
    i64 a[n+5];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    i64 s = 0;
    for(int i = 0; i < n; i++) {
        if(i&1) s -= a[i];
        else s += a[i];
    }
    vector<i64> ans;
    ans.push_back(s);
    for(int i = 0; i < n - 1; i++) {
        ans.push_back(2*a[i] - ans.back());
    }
    for(i64 i : ans) printf("%lld ", i);
    puts("");
}
