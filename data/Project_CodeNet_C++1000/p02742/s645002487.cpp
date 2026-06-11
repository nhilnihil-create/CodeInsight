#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define roundup(n,d) (((n) + ((d)-1)) / (d))

using namespace std;

int main(void){
    long long int h,w;
    cin >> h >> w;
    if(h == 1 || w == 1){
        cout << 1 << endl;
    } else {
        cout << roundup(h*w,2) << endl;
    }
    return 0;
}