#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k, a, b, m;

    cin >> k;
    cin >> a >> b;

    int largest = (b / k) *k;
    if(a <= largest)
        cout << "OK";
    else
        cout << "NG";
  	cout << "\n";
    return 0;

}
