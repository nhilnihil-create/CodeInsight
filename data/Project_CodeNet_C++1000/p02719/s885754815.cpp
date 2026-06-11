#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <iomanip>
using namespace std;
 
int main(){
    long long N, K;
    cin >> N >> K;
    long long m = N / K;
    long long a = N - K * m;
    long long b = abs(N - K * m - K);
    cout << min(a, b) << endl;
    return 0;
}