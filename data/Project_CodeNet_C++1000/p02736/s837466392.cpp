#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <functional>
#include <chrono>
#include <cstring>
#include <limits.h>

using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<lint> vl;
typedef pair<lint,lint> pll;

int main()
{
    ios_base::sync_with_stdio(0);    cin.tie(NULL);    cout.tie(NULL);

    int n; cin>>n;
    vi a(n);
    bool one = false;
    string s; cin>>s;
    for (int i=0; i<n; ++i){
        int &v = a[i];
        v = s[i]-'1';
        //cin>>v; v--;
        if (v==1) one=true;
    }

    auto last = [](vi a){
        int n = a.size();
        int res = 0;
        for (int i = 0; i<n; ++i){
            int cn_1i = (((n-1)|i) == (n-1))?1:0;
            if (cn_1i) res = res^a[i];
        }
        return res;
    };

    if (!one){
        cout<<last(a);
    } else {
        for (int &v: a) if (v==2) v=0;
        cout<<last(a);
    }


}
