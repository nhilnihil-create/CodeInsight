#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
int main () {
    int n;
    int k;
    cin >> n >> k;
    int keta = 0 ;
    while ( n > 0){
        n = n / k ;
        keta++ ;
    }
    cout << keta << endl;
    return 0;
}
