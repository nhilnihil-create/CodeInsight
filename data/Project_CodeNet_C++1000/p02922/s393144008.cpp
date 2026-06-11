#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int sum = 1;
    int ans = 0;
    while(sum < B){
        sum -= 1;
        sum += A;
        ans++;
    }
    cout << ans << endl;
}
