#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    LL T1, T2; cin >> T1 >> T2;
    LL A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    if (A1 - B1 < 0) {
        swap(A1, B1);
        swap(A2, B2);
    }
    LL s1 = (A1-B1)*T1;
    LL s2 = (A2-B2)*T2;
    if ((A1-B1)*T1 + (A2-B2)*T2 > 0)  cout << "0" << endl;
    else if ((A1-B1)*T1 + (A2-B2)*T2 == 0)  cout << "infinity" << endl;
    else  cout << s1/(-(s1+s2)) * 2 - 1 + (s1%(-(s1+s2)) == 0 ? 1 : 2) << endl;

    return 0;
}
