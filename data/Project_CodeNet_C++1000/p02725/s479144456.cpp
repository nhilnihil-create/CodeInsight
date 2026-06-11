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

const int N = 3e5 + 5, M = 2e5 + 5, mod = 1e9 + 9, INF = 0x3f3f3f3f;
char s[N];
int k, n, Max;
int a[N];

inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}

int main()
{
    cin >> k >> n;
    int Max = -1;
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 2; i <= n; ++i) {
        int pos = a[i] - a[i - 1];
        Max = max(Max, pos);
    }
    Max = max(Max, a[1] + k - a[n]);
    cout << k - Max << endl;
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