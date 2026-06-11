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
    int n;
    cin>>n;
    if(n%10==7||(n/10)%10==7||n/100==7) printf("Yes\n");
    else printf("No\n");
    return 0;
}
