#include <bits/stdc++.h>

using namespace std;

int main() {
    int D,T,S;
    cin >> D >> T >>S;
    double passed_time;
    passed_time = (double)D / S;
    if(passed_time <= T){
        cout << "Yes" << endl;
        return 0;
    }
    else{
        cout << "No" << endl;
        return 0;
    }
}