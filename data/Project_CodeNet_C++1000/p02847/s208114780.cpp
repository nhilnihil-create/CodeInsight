#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)

int main(){
    string S;
    cin >> S;
    int d;
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    rep(i,0,7){
        if (day[i] == S){
            cout << 7 - i << endl;
        }
    }
}