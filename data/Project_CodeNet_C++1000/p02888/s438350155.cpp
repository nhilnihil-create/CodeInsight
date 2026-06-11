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
    int n;
    scanf("%d", &n);
    int a[n+2];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            cnt += lower_bound(a, a+n, a[i] + a[j]) - a - j - 1;
            // dbg(cnt);
        }
    }
    printf("%d\n", cnt);
}
