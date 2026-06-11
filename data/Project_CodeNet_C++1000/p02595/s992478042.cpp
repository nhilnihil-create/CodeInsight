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
   
   
    int n, d;
    cin >> n >> d;
    int ans = 0;
    while (n--) {
        double a, b;
        cin >> a >> b;
        if ((double)d * d >= a * a + b * b)ans++;
    }
    cout << ans << endl;
    
    return 0;

}