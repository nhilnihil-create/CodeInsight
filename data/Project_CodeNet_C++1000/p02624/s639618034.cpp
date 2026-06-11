#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>
#include<time.h>
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;



int main()
{

    ll ans = 0;
    int n;
    cin >> n;

    vector<ll>t(n + 2);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            t[j]++;
        }
        ans += i * t[i];
    }
    cout << ans << endl;

    return 0;

}