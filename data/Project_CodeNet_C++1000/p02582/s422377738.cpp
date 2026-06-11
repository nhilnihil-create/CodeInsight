// 173

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    char c;
    vector<bool> v(3);
    for(int i=0; i<3; i++){
        cin >> c;
        if(c == 'R') {v.at(i) = true;}
        else if(c == 'S') {v.at(i) = false;}
    }
    if(v.at(0) && v.at(1) && v.at(2)){cout << 3 << endl; return 0;}
    else if((v.at(0) && v.at(1) && !v.at(2)) || (!v.at(0) && v.at(1) && v.at(2))){cout << 2 << endl; return 0;}
    else if(!v.at(0) && !v.at(1) && !v.at(2)){cout << 0 << endl; return 0;}
    else {cout << 1 << endl; return 0;}
}