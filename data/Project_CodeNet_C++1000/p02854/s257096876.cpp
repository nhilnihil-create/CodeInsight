#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    int n;
    cin >> n;
    vector<long> l(n), ll(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
        if(i == 0) ll[i] = l[i];
        else ll[i] = ll[i-1] + l[i];
    }
    long min = 99999999999999;
    for(int i = 0; i < n; i++){
        long left = ll[i];
        long right = ll[n-1] - ll[i];
        min = std::min(min, abs(left-right));
    }
    cout << min << endl;
    return 0;
}