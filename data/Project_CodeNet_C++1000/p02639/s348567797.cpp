#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    vector<int> a(5);
    rep(i,5) {cin >> a[i]; if(a[i] == 0) cout << i+1 << endl;}
}