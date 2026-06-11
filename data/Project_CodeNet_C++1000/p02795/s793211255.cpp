#include <bits/stdc++.h>
using namespace std;

int main() {
    double h,w,n;
    cin >> h >> w >> n;
    int answer = min(ceil(n/h),ceil(n/w));
    cout << answer;
}