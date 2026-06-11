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

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll>a(n+1), b(m+1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= m; i++)cin >> b[i];

    int x = 0, y = 0;
    int ans = 0;
    ll p = 0;
    vector<ll>ra(n+2), rb(m+2);

    for (int i = 0; i <= n; i++) {
        ra[i] += a[i];
        ra[i + 1] += ra[i];
    }
    for (int i = 0; i <= m; i++) {
        rb[i] += b[i];
        rb[i + 1] += rb[i];
    }
    int j = 0;
    for (int i = n ; i >= 0; i--) {
        if (ra[i] > k)continue;
        while (rb[j]+ra[i] <=   k&&j<=m) {ans = max(ans, j + i);
            j++;
        }
        if(ra[i]+rb[j]<=k && j <= m)ans = max(ans, j + i);
       // cout << i << " " << j << endl;
        
        
    }



    cout << ans << endl;

    return 0;

}
