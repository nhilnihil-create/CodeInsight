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
   
   
    int n;
    cin >> n;
    vector<ll>a(n );

    for (int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j])continue;
            for (int k = j + 1; k < n; k++) {
                if (a[j] == a[k])continue;
                if (a[i] + a[j] <= a[k])break;
                ans++;
            }
        }
    }
    cout << ans << endl;
    
   
    return 0;

}