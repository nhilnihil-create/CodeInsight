// 177

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
    int n; 
    cin >> n;
    n = n%1000;
    if(n == 0) cout << 0 << endl;
    else cout << 1000 - n << endl;
    return 0;
}
