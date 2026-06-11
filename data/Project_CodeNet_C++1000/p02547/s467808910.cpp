#include <bits/stdc++.h>
using namespace std;;

int main(){
    int n;
    cin >> n;
    int a,b;
    int flag = 0;
    string ans = "No";
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (a==b){
            flag++;
        }else{
            flag = 0;
        }

        if (flag == 3){
            ans = "Yes";
        }

    }
    cout << ans << endl;
}