#include <iostream>
#include <numeric>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>
#include <iterator>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < (n); i++) 
using namespace std;

int main() {
    long long int n,l,ans=0, sum=0, min_num=200;
    int j;
    cin >> n >> l;
    vector<int> v(n);
    rep(i,n) {
        v[i] = l + (i+1) -1;
    }
    sum = accumulate(v.begin(), v.end(), 0);
    //sort(v.begin(), v.end());
    rep(i,n) {
        if(abs(v[i]) < min_num) {
            min_num = abs(v[i]);
            j = i;
        }
    }
    v.erase(v.begin() + j); 
    rep(i,n-1) {
        ans += v[i];
    } 
    cout << ans << endl;

    return 0;
}