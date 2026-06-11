#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>


using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

int a[1000001];

int main(void)
{
  int K;
    scanf("%d",&K);
    a[1]=7%K;
    for(int i=2;i<=K;i++)a[i]=(a[i-1]*10+7)%K;

    for(int i=1;i<=K;i++)if(a[i]==0){
        printf("%d\n",i);
        return 0;
    }
    printf("-1\n");

  return 0;
}
