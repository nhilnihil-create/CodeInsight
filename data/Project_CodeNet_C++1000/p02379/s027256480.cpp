
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef long long ll;

int main(){
    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double ans = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    printf("%.5f\n",ans);
    return 0;
}