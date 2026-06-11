#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n/2; i++){
        int x = n-i;
        if(x != i){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}