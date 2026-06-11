#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n;

int main() {
    while(cin >> n, n){
    int a[1001]={0};
    for(int i=0; i<n; ++i)  cin >> a[i];
    sort(a, a+n);
    int minV=1000000;
    for(int i=1; i<n; ++i){
        minV = min(minV, abs(a[i]-a[i-1]));
    }
    cout << minV << endl;
    }
    return 0;
}
