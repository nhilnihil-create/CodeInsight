#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int main() {
    long long a,b;
    cin>>a>>b;
    a%=b;
    if(b-a<a) a=b-a;
    printf("%lld\n",a);
    return 0;
}
