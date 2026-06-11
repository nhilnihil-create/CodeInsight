#include <iostream>
using namespace std;

int main(){

    int m, n;
    int a[10000];
    int sum = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        sum += a[i];
    }
    n -= sum;

    if(n < 0){
        cout << -1;
    }else{
        cout << n;
    }

    return 0;
}