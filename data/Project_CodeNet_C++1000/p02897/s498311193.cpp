#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    double n, odd=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        if(i%2 == 1) odd++;
    }
    cout << odd/n << endl;
    return 0;
}