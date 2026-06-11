#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{
    ll h;
    cin >> h;
 
    ll count = 0;
    ll base = 1;
    while(h > 0) {
         count += base;
         h = h / 2;
         base <<= 1;
    }
 
    cout << count << endl;


    return 0;
}