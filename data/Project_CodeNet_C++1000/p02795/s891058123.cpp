#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int x = max(h,w);
    if(n % x == 0){
        cout << n / x << endl;
    }else{
        cout << n / x + 1 << endl;
    }
    return 0;
}
