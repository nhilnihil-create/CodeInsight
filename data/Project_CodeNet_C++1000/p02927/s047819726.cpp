#include <iostream>
using namespace std;

int main()
{
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for(int i = 0; i <= d; i++){
        int e = i / 10;
        int f = i % 10;
        if(e >= 2 && f >= 2 && e * f <= m) ans++;
    }
    cout << ans << endl;
}
