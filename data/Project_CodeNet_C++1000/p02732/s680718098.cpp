#include<iostream>
using namespace std;
#define MAX_N 200010

int main() {
    long long n, a[MAX_N];
    long long dic[MAX_N]= {};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        dic[a[i]]++;
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dic[i] * (dic[i] - 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        if (dic[a[i]] > 1) cout << sum - dic[a[i]] + 1 << endl;
        else cout << sum << endl;
    }
}