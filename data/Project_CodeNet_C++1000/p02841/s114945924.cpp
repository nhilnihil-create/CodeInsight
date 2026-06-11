#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    int m1,d1,m2,d2;
    scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
    if(m1 != m2) printf("1\n");
    else printf("0\n");
    return 0;
}