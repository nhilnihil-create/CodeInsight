#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define Rep(i,n) for(int i=1;i<=(n);++i)
using LL = long long;
using ULL = unsigned long long;

const int INF = 0x3f3f3f3f;
const int dx[]{-1, 0, 1, 0};
const int dy[]{0, -1, 0, 1};

char s[200123];

int main()
{
    scanf("%s", s);
    for(int i = 0; s[i]; ++i) if(s[i] == '?') s[i] = 'D';
    puts(s);
    return 0;
}