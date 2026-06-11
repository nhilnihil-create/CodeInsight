#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    while(1){
        string s;
        cin >> s;
        if(s=="-") break;
        int m;
        cin >> m;
        string tmp;
        FOR(i, 0, m){
            int h;
            cin >> h;
            tmp = s.substr(0, h);
            s.erase(0, h);
            s = s + tmp;
        }
        cout << s << endl;
    }
}