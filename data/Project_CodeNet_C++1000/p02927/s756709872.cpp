#include<bits/stdc++.h>
using namespace std;

int main()
{
    int M, D;
    cin >> M >> D;
    int cnt = 0;
    for(int i = 1; i <= M; ++i) {
        for(int j = 2; j <= D/10; ++j) {
            for(int k = 2; (10*j+k) <= D && k <= 9; ++k) {
                if(j*k == i) ++cnt;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
