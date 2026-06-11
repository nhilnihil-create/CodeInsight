#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>
#include <cstdint>
#define _USE_CMATH_DEFINES

const long INF = (1l << 30);
const long LINF = (1l << 60); //1.15*10^18

long solve(long n, std::vector<long> d){
    std::sort(d.begin(), d.end());
    return d[n/2] - d[n/2-1];
}

int main(){
    long n;
    scanf("%ld", &n);
    std::vector<long> d(n);
    for(int i = 0; i < n; i++){
        std::cin >> d[i];
    }
    printf("%ld\n", solve(n, d));
}
