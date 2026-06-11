#include <iostream>
using namespace std;
int main(void){
    int X;
    cin >> X;
    int ans = X-1;
    bool is_prime = false;
    while(!is_prime){
        ans++;
        is_prime = true;
        for(int i=2;i*i <= ans;i+=2){
            if(ans % i == 0){
                is_prime = false;
                break;
            }
            if(i == 2)i--;
        }
    }
    cout << ans << endl;
}
