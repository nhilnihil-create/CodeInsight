#include <bits/stdc++.h>
using namespace std;;

int main(){
    int a,ans;
    for (int i = 0; i < 5; i++){
        cin >> a;
        if (a==0){
            ans = i+1;
        }
    }
    cout << ans << endl;
}