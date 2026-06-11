#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    //10で割れる回数...?
    if(n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    long long cnt = 0;
    long long waru = 10;
    while(true){
        if(n/waru > 0){
            cnt += n / waru;
            waru *= 5;
        }else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}


