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

//#include<bits/stdc++.h>


using namespace std;


int main()
{

    string p;
    cin >> p;

    vector<int>a(p.size()+1), b(p.size()+1);
    int x = 0;
    int n = p.size();long g = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == '<')a[i + 1] += a[i] + 1;
       

    }
    for (int i = n-1; i >=0; i--) {
        if (p[i] == '>')b[i ] += b[i+1] + 1;


    }
    for (int i = 0; i <= n; i++) {
        g += max(a[i], b[i]);
        //cout << a[i]<<" "<<b[i] << endl;
    }

    cout << g << endl;
    


    
   

    return 0;

}