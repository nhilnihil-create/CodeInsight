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
    string s;
    cin >> s;
    if (s[2] == s[3] && s[4] == s[5] && s.size() == 6) printf("Yes\n");
    else printf("No\n");
    return 0;
}
