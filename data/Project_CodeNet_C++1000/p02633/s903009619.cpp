#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int now = 0;
    int ans = 0;
    while(1){
        if(now == 360){
            break;
        }

        now += n;
        ans++;
        if(now > 360){
            now -= 360;
        }
    }

    cout << ans << endl;
}