#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    int m,d;
    int ans = 0;
    cin >> m >> d;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= d; j++){
            int a = j%10;
            int k = j/10;
            if(a < 2 || k < 2)continue;
            if(a * k == i)ans++;
        }
    }

    cout << ans << endl;
}