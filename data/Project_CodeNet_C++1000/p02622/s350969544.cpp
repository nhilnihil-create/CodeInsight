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
    string s;
    string t;
    cin >> s;
    cin >> t;
    
    int ans = 0;
    
    for (int i = 0 ;i < s.size();i++){
        if (s[i] == t[i]){
            ;
        }
        else {
            ans++;
        }
    }
    cout << ans << endl;
}
