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
    vector<int>a(n);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
 //   cout << a[m - 1];
    int r = 0;
    for (int i = 0; i < n; i++) {
        if ((double)a[i] >= (double)(ans / (4 * m)))r++;
    }
    if (r>=m)cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;

}