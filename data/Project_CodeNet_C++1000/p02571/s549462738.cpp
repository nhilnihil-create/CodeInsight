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
   
   
    string s, t;
    cin >> s >> t;
    int ans = 99999999;
    for (int i = 0; i <= s.size() - t.size(); i++) {
        int a = 0;
        for (int j = 0; j < t.size(); j++) {
            if (s[i+j] != t[j])a++;
        }
      
        ans = min(a, ans);
    }

    cout << ans << endl;
   
    return 0;

}