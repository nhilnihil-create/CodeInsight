#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
    int n;
    cin >> n; 
    if(n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 10 || n == 12 || n == 14 || n == 16 || n == 18 || n == 15 || n == 21 || n == 24 || n == 27 || n == 16 || n == 20 || n == 28 || n == 32 || n == 36 || n == 25 || n == 30 || n == 35 || n == 40 || n == 45 || n == 36 || n == 42 || n == 48 || n == 54 || n == 49 || n == 56 || n == 63 || n == 64 || n == 72 || n == 81)cout << "Yes" << endl;
    else cout << "No" << endl;
}