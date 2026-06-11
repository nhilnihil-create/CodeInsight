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

int main(){
    int a, b;
    cin >> a >> b;
    if(a < 10 && b < 10){
        cout << a * b << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
