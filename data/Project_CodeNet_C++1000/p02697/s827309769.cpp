#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+111;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int fi=1,se=m+1;
    while(fi<se){
        printf("%d %d\n",fi,se);
        ++fi,--se;
    }
    fi=m+2,se=(m<<1|1);
    while(fi<se){
        printf("%d %d\n",fi,se);
        ++fi,--se;
    }
    return 0;
}