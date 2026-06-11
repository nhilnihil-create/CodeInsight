#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map> 
#include <stack>
#include <sstream>
#include <set>
#pragma GCC optimize(2)

//#define int long long
#define mm(i,v) memset(i,v,sizeof i);
#define mp(a, b) make_pair(a, b)
#define pi acos(-1)
#define fi first
#define se second
//你冷静一点，确认思路再敲！！！ 

using namespace std;
typedef long long ll;
typedef pair<int, int > PII;
priority_queue< PII, vector<PII>, greater<PII> > que;
stringstream ssin; //  ssin << string   while ( ssin >> int)

const int N = 1e5 + 5, M = 2e5 + 5, mod = 1e9 + 9, INF = 0x3f3f3f3f;
char s[N];
int k;

inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}

int main()
{
    scanf("%s", s + 1);
    if (s[3] == s[4] && s[5] == s[6]) puts("Yes");
    else puts("No");
    // system("pause");
    return 0;
}
/*
niuniu
1
abca
2
abcabc
2
*/