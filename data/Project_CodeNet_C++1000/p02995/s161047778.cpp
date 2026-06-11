#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cctype>
#include <bitset>
using namespace std;
int main()
{
    long int i,a,b,c,d,cc,ccc,cccc,dd,ddd,dddd,cd,cdcd,cdcdcd,cdcdcdcd,answer;
    cin >> a >> b >> c >> d;
    answer = 0;
    if(a % c == 0){
        cc = a;
    }
    else{
        cc = (a - (a % c)) + c;
    }
    if (b % c == 0){
        ccc = b;
    }
    else{
        ccc = (b - (b % c));
    }
    cccc = ((ccc - cc) / c) + 1;
    if (a % d == 0){
        dd = a;
    }
    else{
        dd = (a - (a % d)) + d;
    }
    if (b % d == 0){
        ddd = b;
    }
    else{
        ddd = (b - (b % d));
    }
    dddd = ((ddd - dd) / d) + 1;
    cd = (c * d) / __gcd(c,d);
    if (a % cd == 0){
        cdcd = a;
    }
    else{
        cdcd = (a - (a % cd)) + cd;
    }
    if (b % d == 0){
        cdcdcd = b;
    }
    else{
        cdcdcd = (b - (b % cd));
    }
    cdcdcdcd = ((cdcdcd - cdcd) / cd) + 1;
    cout << b - a + 1 -(cccc + dddd - cdcdcdcd) << endl;
}