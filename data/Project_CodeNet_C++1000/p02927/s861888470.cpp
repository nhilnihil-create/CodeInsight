#include <iostream>
using namespace std;

int main(){

    int i, j, k, m, d, cnt = 0;
    cin >> m >> d;
    int d1 = d % 10, d10 = d / 10;
    // cout << d1 << " " << d10 <<endl;


    for(i = 1; i <= m; i++ ){
        for(j = 1; j <= d; j++){            
            int d1 = j % 10, d10 = j / 10;
            if(d1 < 2 || d10 < 2) continue;
            if(d1 * d10 == i) cnt++;
        }
    }

    cout << cnt <<endl;
    return 0;
}