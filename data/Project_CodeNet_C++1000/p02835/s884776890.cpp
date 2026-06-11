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
        cout << "win" << endl;
    } else {
        cout << "bust" << endl;
    }   
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    bool res = ((a + b + c) <= 21);
    print_ans(res);
    return 0;
}
