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

   
    string p;
    cin >> p;

    int n = p.size() / 2;
    int da = n, db = n;
    if (p.size() % 2) {
        da = n - 1; db = n + 1;
    }
    
    string a = p.substr(0, p.size()/2 );
    string b = p.substr(db, p.size() );
    bool f = 0;
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size()/2; i++) {
        if (a[i] != a[a.size() - 1 - i])f = 1;
        if (b[i] != b[b.size() - 1 - i])f = 1;
    }
   // cout << a << endl;
   // cout << b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            f = 1;
        }
    }
    if (f)cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;

}