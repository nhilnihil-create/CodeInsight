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
    string s,t;
    cin >> s >> t;
    bool ok = 1;
    for(int i = 0; i<s.size(); i++){
        if(s[i] != t[i]){
            ok = 0;
        }
    }
    if(ok == 1){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}
