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
   
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        n -= t;
    }
    if (n < 0)cout << -1 << endl;
    else cout << n << endl;

    return 0;

}