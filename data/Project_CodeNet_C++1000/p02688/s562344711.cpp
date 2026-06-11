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
int main(){
    int n,k,d,i,j,p;
    cin >> n >> k;
    int P[n + 1] = {};
    for(i = 0;i < k;i++){
        cin >> d;
        for(j = 0;j < d;j++){
            cin >> p;
            P[p]++;
        }
    }
    p = 0;
    for(i = 1;i <= n;i++){
        if(P[i] == 0) p++;
    }
    cout << p << endl;
}