#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    string ans="No";
    cin >> N;
    for (int i = 1; i <= 9; i++){
        int a = N/i;
        int b = N%i;
        if(a<=9 && b==0){
            ans = "Yes";
            break; 
        }
    }
    cout << ans << endl;
}