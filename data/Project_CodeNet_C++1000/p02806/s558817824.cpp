#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


int main(){
    int n;  cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        cin >> t[i];
    }
    string x;   cin >> x;
    int res = 0;
    bool state = false;
    for(int i = 0; i < n; i++){
        if(state){
            res += t[i];
        }
        if(x == s[i])   state = true;
    }

    cout << res << endl;

    return 0;
}
