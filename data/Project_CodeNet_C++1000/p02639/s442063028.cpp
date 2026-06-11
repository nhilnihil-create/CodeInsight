#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = -1;
    int ans = 0;
    for(int i = 1; i <= 5; i++){
        cin >> num;
        if(num == 0){
            ans = i;
        }
    }

    cout << ans << endl;


}