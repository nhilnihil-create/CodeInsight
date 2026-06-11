#include <iostream>
using namespace std;

int main(){
    int n,k,cnt = 0,N;
    cin >> n >> k;
    N = n;

    while(1){
        n = n / k;
        cnt++;
        if(n < k){
            cnt++;
            break;
        }
    }

    if(N < k) {cout << 1 <<endl;}
    else {cout << cnt << endl;}

}