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

long m, dig, sum;
long d[200005];
long c[200005];

int main(){
    scanf("%ld", &m);
    for(int i = 0; i < m; i++){
        scanf("%ld%ld", d+i, c+i);
        dig += c[i];
        sum += d[i] * c[i];
    }
    printf("%ld\n", dig - 1 + (sum - 1) / 9);
}
