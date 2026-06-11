#include <stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fr first
#define sc second
#define scl(n) scanf("%lld", &n)
#define scd(n) scanf("%lf", &n)
#define scc(n) scanf(" %c", &n)
#define scs(n) scanf(" %s", n)
#define pll pair<ll, ll>
#define bigprime 9867589359258017
#define pbase 925943
#define pmod 1351782499
#define pi acos(-1.0)

int main()
{
    ll n, m, i, j;
    while(1)
    {
        scl(n);
        scl(m);
        if(n==0 && m==0)
            break;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(i%2==1)
                {
                    if(j%2==1)
                        printf("#");
                    else
                        printf(".");
                }
                else
                {
                    if(j%2==0)
                        printf("#");
                    else
                        printf(".");
                }
            }
            cout<<endl;
        }
        cout<<endl;

    }


}








