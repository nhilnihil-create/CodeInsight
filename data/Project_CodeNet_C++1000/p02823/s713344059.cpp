#include <bits/stdc++.h>
using namespace std;

long long n, a, b, res;

int main(){
    cin >> n >> a >> b;
    if ((b-a)%2==0){
        res = (b-a)/2;
    } else {
        if (a-1<n-b) {
            res = a-1 + (b-a-1)/2 +1;
        } else {
            res = n-b + (b-a-1)/2 +1;
        }
    }
    cout << res;
    return 0;
}