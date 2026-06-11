#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        int smin=n;
        for(int z=0; z*z*z<=n; z++){
            int diff = n-z*z*z;
            int y = sqrt(diff);
            int x = diff - y*y;
            smin = min(x+y+z ,smin);
        }
        cout << smin << endl;
    }
    return 0;
}