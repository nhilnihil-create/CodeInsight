#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, ans = "Yes";
    cin >> s;
    for(int i = 0; i < (int)s.length(); i++){
        if(i % 2 == 0 && s[i] == 'L'){
            ans = "No";
            break;
        }
        if(i % 2 == 1 && s[i] == 'R'){
            ans = "No";
            break;
        }
    }
    cout << ans;
    return 0;
}