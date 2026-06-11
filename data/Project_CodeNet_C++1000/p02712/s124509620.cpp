#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long num,sum=0;
    cin >> num;
    //vector<long long> list;
    for (int i=1; i<=num; i++) {
        if (i%3!=0 && i%5!=0) {
            sum+=i;
        }}
    cout << sum;
}