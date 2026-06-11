#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int h,w,n;
    int c = 0;
    
    cin >> h >> w >> n;
    
    int t = max(h,w);
    
    while(n>0){
        n -= t;
        c++;
    }
    cout << c << endl;
}

