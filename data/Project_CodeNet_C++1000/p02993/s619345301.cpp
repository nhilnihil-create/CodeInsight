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
    cin >> s;
    int ans = 1;
    for (int i = 0;i < 3;i++){
        if (s[i] == s[i+1]){
            ans = 0;
            break;
        }
    }
    if (ans == 1){
        cout << "Good" << endl;
    }
    else {
        cout << "Bad" << endl;
    }
}
