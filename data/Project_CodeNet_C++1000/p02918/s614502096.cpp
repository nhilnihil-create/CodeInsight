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
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s + "#";
    // n += 2;
    int unhappy = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'L') unhappy += (s[i-1] != 'L');
        else unhappy += (s[i+1] != 'R');
    }
    unhappy -= k*2;
    unhappy = max(0, unhappy);
    if(!unhappy) unhappy++;
    cout << n - unhappy << "\n";
}
