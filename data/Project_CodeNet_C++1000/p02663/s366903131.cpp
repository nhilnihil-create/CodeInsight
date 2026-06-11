#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int h1,h2,m1,m2,k;
    cin >> h1 >> m1 >> h2 >> m2>> k;
    int time = h2*60 + m2 - h1*60 -m1;
    cout << time-k << endl;
    return 0;
}