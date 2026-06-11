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
    int n,k;
    string s;
    
    cin >> n >> k;
    cin >> s;
    
    int rl[2] = {0};
    if (s[0] == 'L'){
        rl[0] = 1;
    }
    
    if (s[n-1] == 'R'){
        rl[1] = 1;
    }
    
    int unha = 0;
    for (int i = 0;i < n-1;i++){
        if (s[i] == 'R' && s[i+1] == 'L'){
            unha++;
        }
    }
    if (unha > k){
        cout << n-(2*(unha-k) + rl[0] + rl[1]) << endl;
    }
    else if (unha == k && rl[0] == 1 && rl[1] == 1){
        cout << n-2 << endl;
    }
    else {
        cout << n-1 << endl;
    }
    
}
