#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <iomanip>
using namespace std;
 
int main(){
    long double L;
    cin >> L;
    cout << fixed << setprecision(15) << L * L * L / 27 << endl;
    return 0;
}