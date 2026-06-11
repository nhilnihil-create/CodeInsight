#include <iostream>
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

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int ans = -1;
    
    int x = n/1.08;
    int y = (n+1)/1.08;
    
    
    if (x*1.08 >= n && x*1.08 < n+1){
        ans = x;
    }
    
    if (y*1.08 >= n && y*1.08 < n+1){
        ans = y;
    }

    if (ans == -1){
        cout << ":(" << endl;
    }
    else {
        cout << ans  << endl;
    }
}
