#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int x, y;
    cin >> x >> y;
    if(y%2 == 1) cout << "No" << endl;
    else if( y>=2*x && y<=4*x) cout << "Yes"<<endl;
    else cout << "No" << endl;
}