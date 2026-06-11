#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(void)
{
    int K, A, B;

    cin >> K >> A >> B;

    int ans = B/K - (A-1)/K;

    if(ans == 0){
        cout << "NG" << endl;
    } else {
        cout << "OK" << endl;
    }

    return 0;
}
