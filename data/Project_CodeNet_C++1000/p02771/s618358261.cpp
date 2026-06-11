#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    string ans;
    ans = "No";

    if(a == b && a != c){
        ans = "Yes";          
    }
    if(a == c && a != b){
        ans = "Yes";         
    }
    if(c == b && b != a){
        ans = "Yes";          
    }
    
    cout << ans << endl;
    

}