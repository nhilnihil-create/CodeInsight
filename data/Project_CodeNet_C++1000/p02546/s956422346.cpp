#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stack>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    auto n = s.size();
    if(s.at(n-1) == 's'){
        s = s + "es";
    }else{
        s = s + "s";
    }
    cout << s << '\n';
}
