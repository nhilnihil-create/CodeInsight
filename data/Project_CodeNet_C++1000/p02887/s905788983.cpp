#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int i = 0, j = 0, len =n;
    while(j<n){
        if(s[i] == s[j]){
        if(i!=j)len--;
            j++;
        }
        else{
            i=j;
        }
    }
    
    cout << len;
    
}


