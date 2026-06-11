#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
#include <vector>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)

const int INF = 1e9;

using namespace std;

int main() {
    int h, w;
    ostringstream os;
    while(1){
        cin >> h >> w;
        if (h + w == 0)
            break;
        REP(i, h){
            os << "#";
            if (i == 0 || i == h-1)
                REP(i, w-2) os << "#";
            else
                REP(i, w-2) os << ".";
            os << "#";
            os << endl;
        }
        os << endl;
    }
    cout << os.str();
    return 0;
}