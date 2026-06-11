#include <iostream>
using namespace std;
int main()
{
    int m, d, k, d1d10, ans = 0;
    cin >> m >> d;
    for(int i = 4; i <= m; i++){
        for(int j = 22; j <= d; j++){
            d1d10 = 1;
            k = j;
            while(k != 0){
                if(k % 10 < 2) k = 0;
                d1d10 *= (k % 10);
                k /= 10;
            }
            if(i == d1d10) ans++;
        }
    }
    cout << ans << endl;
}