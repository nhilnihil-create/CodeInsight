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


    int k;
    cin >> k;
    vector<int>a(k + 3);
    a[0] = 7 % k;
    for (int i = 0; i <= k; i++) {
        
        if (!a[i]) {
            cout << i+1 << endl;
            return 0;
        }
        a[i+1] = (a[i ] * 10 + 7) % k;
        
    }
    cout << -1 << endl;
    return 0;

}
