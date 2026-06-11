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
typedef long long int ll;
//#include<bits/stdc++.h>


using namespace std;

vector<long long int>a(500005), b(500005);



int main()
{
    
    string p;
    cin >> p;
    int a = 0;
    int n = p.size();
    for (int i = 0; i < p.size() / 2; i++) {
        if (p[i] == p[n - i - 1])continue;
        a++;
    }
    cout << a << endl;

    return 0;

}