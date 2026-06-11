#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    long long a,v;
    cin >> a >> v;
    long long b,w;
    cin >> b >> w;
    long long t;
    cin >> t;
    long long d = abs(a-b);
    long long d2 = (v-w)*t;
    cout << (d <= d2 ? "YES" : "NO") << endl;
    return 0;
}