#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
#include<complex>
using namespace std;

int main(){
    int r, s, x;
    cin >> r >> s;
    int S = 0;
    int rS;
    int cS[s] = {};
    for (int i=0;i<r;i++){
        rS = 0;
        for (int j=0;j<s;j++){
            cin >> x;
            cout << x << " ";
            S += x;
            rS += x;
            cS[j] += x;
        }
        cout << rS << endl;
    }
    for (int j=0;j<s;j++){
        cout << cS[j] << " ";
    }
    cout << S <<endl;

    return 0;
}