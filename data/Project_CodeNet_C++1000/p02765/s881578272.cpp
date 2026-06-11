#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
 

int main() {
    int n,r;
    cin >> n >> r;
    cout << ((n>=10)? r : r + 100*(10-n)) << endl; 
}