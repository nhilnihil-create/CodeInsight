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
    int N,i,j,p,a = 10000000;
    cin >> N;
    int X[N];
    for(i = 0;i < N;i++) cin >> X[i];
    for(i = 0;i <= 100;i++){
        p = 0;
        for(j = 0;j < N;j++){
            p += pow(X[j] - i,2);
        }
        if(a > p){
            a = p;
        }
    }
    cout << a << endl;
}