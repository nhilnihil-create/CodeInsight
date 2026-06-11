#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1], b[n];
    for (int i=0; i<n+1; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    long long sum = 0;
    //c[i],d[i]はi番目の勇者がそれぞれi番目、i+1番目の街で倒すモンスターの数
    //i番目の勇者はi番目の街のモンスターを優先して倒すことにする
    int c[n], d[n];            
    c[0] = min(a[0], b[0]);     
    d[0] = min(b[0]-c[0], a[1]);
    sum += c[0] + d[0];
    for (int i=1; i<n; i++) {
        c[i] = min(a[i]-d[i-1], b[i]);
        d[i] = min(b[i]-c[i], a[i+1]);
        sum += c[i] + d[i];
    }
    cout << sum << endl;
}