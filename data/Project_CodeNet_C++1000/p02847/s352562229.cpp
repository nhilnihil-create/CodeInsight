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

    //map<string, int>a;
   
    int t;
    if (p == "SUN")t = 7;
    if (p == "MON")t = 6;
    if (p == "TUE")t = 5;
    if (p == "WED")t = 4;
    if (p == "THU")t = 3;
    if (p == "FRI")t = 2;
    if (p == "SAT")t = 1;
    cout << t << endl;



    return 0;

}