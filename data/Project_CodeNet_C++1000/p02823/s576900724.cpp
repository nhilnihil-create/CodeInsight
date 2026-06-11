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
    long n, a, b;
    cin >> n >> a >> b;

    if(abs(a-b)%2 == 0){
        cout << abs(a-b)/2 << endl;
    }else{
        long l = min(a,b) - 1, r = n - max(a,b); 
        long lans = l + 1 + (max(a,b) - l - 1)/2, rans = r + 1 + (n - min(a,b) - r - 1)/2;
        cout << min(lans, rans) << endl;
    }
    return 0;
}