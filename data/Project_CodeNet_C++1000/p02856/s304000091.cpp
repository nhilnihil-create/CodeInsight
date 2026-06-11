#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int m;
    cin >> m;
    ll s = 0, t = 0;
    for(int i = 0; i < m; i++){
        ll d, c;
        cin >> d >> c;
        s += c;
        t += d * c;
    }
    cout << s - 1 + (t - 1) / 9 << endl;
}
