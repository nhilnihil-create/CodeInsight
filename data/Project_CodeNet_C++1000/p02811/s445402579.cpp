#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

void print_ans(bool flag){
    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }   
}


int main(){
    int k, x;
    cin >> k >> x;
    print_ans(500*k >= x);
    return 0;
}
