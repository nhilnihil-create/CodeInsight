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
    int x;
    cin >> x;
    int ans = 0;
    
    if (x <= 99){
        cout << 0 << endl;
    }
    else {
        int s;
        if (x%105 == 0){
            s = x/105;
        }
        else {
            s = x/105 +1;
        }
        int e = x/100;
        for (int i = s;i <= e;i++){
            if (x-100*i >= 0 && x-100*i <= 5*i){
                ans = 1;
                break;
            }
        }
        cout << ans << endl;
    }
}
