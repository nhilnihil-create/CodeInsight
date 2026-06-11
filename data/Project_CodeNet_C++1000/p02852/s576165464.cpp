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
typedef pair<int, int> P;


int main(){
    int n, m;   cin >> n >> m;
    string s;   cin >> s;

    vector<P> seList;
    seList.emplace_back(P(n, n));
    while(true){
        int nextEnd = seList[seList.size()-1].fs-1;
        int nextStart = max(0, seList[seList.size()-1].fs - m);
        while(s[nextEnd] == '1'){
            nextEnd--;
        }
        while(s[nextStart] == '1'){
            nextStart++;
        }

        if(nextStart > nextEnd){
            cout << -1 << endl;
            return 0;
        }

        seList.emplace_back(P(nextStart, nextEnd));

        if(nextStart == 0){
            break;
        }
    }

    reverse(seList.begin(), seList.end());
    int now = 0;
    for(auto range: seList){
        if(range.fs == 0){
            continue;
        }
        cout << range.fs - now << " ";
        now = range.fs;
    }

    cout << endl;


    return 0;
}
