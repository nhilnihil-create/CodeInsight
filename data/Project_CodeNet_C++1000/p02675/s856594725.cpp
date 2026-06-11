#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    if(n <= 0 || n > 999)
        return 0;

    int so = n % 10;

    if (so == 2 || so == 4 || so == 5 || so == 7 || so == 9)
    {
        cout << "hon";
    }
    else if (so == 0 || so == 1 || so == 6 || so == 8)
        cout << "pon";
    else
        cout << "bon";

    return 0;
}
