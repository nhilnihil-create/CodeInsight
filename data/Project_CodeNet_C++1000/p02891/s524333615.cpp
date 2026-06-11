#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef double f32;
typedef long long i64;
const int N = 1e5+5;
int n, k; i64 v[3]; string s, t;
int main()
{
    cin>>s>>k, t = s+s+s;
    for(int i = 1; i < t.size(); ++i) if(t[i] == t[i-1]) t[i] = '.', ++v[i/s.size()];
    printf("%lld\n", v[0]+k/2*v[1]+(k-1)/2*v[2]);
    return 0;
}