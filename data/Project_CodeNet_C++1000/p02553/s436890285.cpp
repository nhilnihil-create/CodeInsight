#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <set>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

long long mymax(long x, long y){ return x>y? x: y;}

int main(void){
    long long a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

    printf("%lld\n", mymax(a*c, mymax(a*d, mymax(b*c, b*d))));
    return 0;
}