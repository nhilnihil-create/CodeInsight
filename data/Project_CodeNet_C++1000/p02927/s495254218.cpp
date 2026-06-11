#include<iostream>

using namespace std;

int main(){
    int m, d;
    int ans = 0;
    cin >> m >> d;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= d; j++){
            int d_1 = j % 10;
            int d_10 = j / 10;

            if(d_1 >= 2 && d_10 >= 2 && d_1 * d_10 == i){
                ans++;
            }
        }
    }

    cout << ans;
}
