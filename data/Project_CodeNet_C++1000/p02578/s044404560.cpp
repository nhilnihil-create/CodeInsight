#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    long long cnt = 0;
    long long previous = 0;
    for (int i = 1; i <= n; i++){
        long long height; cin >> height;
        if (height < previous) {
            cnt += previous - height;
            height = previous;
        }
        previous = height;
    }
    cout << cnt << endl;
}