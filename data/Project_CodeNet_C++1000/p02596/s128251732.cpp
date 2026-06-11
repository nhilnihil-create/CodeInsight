#include <iostream>

using namespace std;
int n;
int main(){
    cin >> n;
    int cnt = 1;
    if (n % 2 == 0) cout << -1;
    else{
        int sum = 7;
        while (cnt <= 1e7 && sum % n > 0){
            cnt++;
            sum = (sum * 10 + 7) % n;
        }
        if (cnt > 1e7) cout << -1; else cout << cnt;
    }
}
