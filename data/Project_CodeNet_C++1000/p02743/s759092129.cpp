#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
int main(){
    long double eps = 1.0E-14;
    long double A,B,C;
    cin >> A >> B >> C;
    long double AA,BB,CC;
    AA = sqrtl(A);
    BB = sqrtl(B);
    CC = sqrtl(C);

    if(AA + BB + eps < CC) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
