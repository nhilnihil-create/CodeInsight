#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cctype>
using namespace std;
typedef long long ll;
typedef vector<int> veci;
typedef vector<ll> vecl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <class T>
inline void read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return ;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1:1;
    ret = (c == '-') ? 0:(c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return ;
}
inline void outi(int x) {if (x > 9) outi(x / 10);putchar(x % 10 + '0');}
inline void outl(ll x) {if (x > 9) outl(x / 10);putchar(x % 10 + '0');}

using namespace std;

int k;
int main()
{
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cout<<"ACL";
    }
    cout<<endl;
    
}
