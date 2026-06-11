#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    long long h;
    int n;
    cin >> h >> n;
    rep(i,n){
        long long a;
        cin >> a;
        h -= a;
    }
    if(h <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}