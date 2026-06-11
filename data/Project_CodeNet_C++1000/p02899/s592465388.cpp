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
int a[100005],b[100005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    printf("\n");
}
