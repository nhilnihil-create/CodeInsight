#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    long long x, y;
    cin >> n >> d;
    int count = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(sqrt(x * x + y * y) <= d){
            count++;
        }
    }
    cout << count << endl;
}