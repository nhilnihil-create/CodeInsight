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
    int n, r_c=0, w_c=0, count=0;
    cin >> n;
    char c;
    vector<bool> v(n);
    for(int i=0; i<n; i++){
        cin >> c;
        if(c == 'R') {v.at(i) = true; r_c++;}
        else if(c == 'W') {v.at(i) = false; w_c++;}
    }
    for(int i=0; i<r_c; i++){
        if(!v.at(i)) count++;
    }
    cout << count << endl;
    return 0;
}
