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

const long INF = (1l << 30);
const long LINF = (1l << 60);

long t1, t2, a1, a2, b1, b2;
long d1, d2;

int main(){
    scanf("%ld%ld%ld%ld%ld%ld", &t1, &t2, &a1, &a2, &b1, &b2);
    d1 = t1*(a1-b1);
    d2 = t2*(a2-b2);
    if(d1 + d2 == 0){
        printf("infinity\n");
        return 0;
    }
    if((d1 > 0 && (d1 + d2) > 0) || (d1 < 0 && (d1 + d2) < 0)){
        printf("0\n");
        return 0;
    }
    if((d1 + d2) < 0){
        d1 = -d1;
        d2 = -d2;
    }
    //printf("%ld %ld\n", d1, d2);
    long n = (-d1) / (d1 + d2);
    if((-d1) % (d1 + d2) == 0){
        printf("%ld\n", 2 * n);
    }else{
        printf("%ld\n", 2 * n + 1);
    }
}
