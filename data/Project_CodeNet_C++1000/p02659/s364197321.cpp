#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A,ans;
    long long At, Ab;
    double B;
    cin >> A >> B;
    Ab = A % 100;
    At = (long long)((A - Ab)/100);
    int Bc = (int)(B*100 + 0.00005);
    ans = At*Bc + (int)(Ab*B);
    cout << ans << endl;
}

