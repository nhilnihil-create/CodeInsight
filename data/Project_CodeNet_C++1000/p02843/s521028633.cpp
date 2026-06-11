#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; i++)
const int INF = 1e9;
const int E = numeric_limits<int>::min();

int main(void)
{
    int X;
    cin >> X;

    queue<int> q;
    map<int, bool> m;
    q.push(0);
    m[0] = true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 100; i <= 105; i++){
            if ((f + i) == X){
                cout << 1 << endl;
                return 0;
            }
            else if ((f + i) < X && m[f+i] == false){
                m[f + i] = true;
                q.push(f + i);
            }
        }
    }
    cout << 0 << endl;
    return 0;
}