#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string s, t;
    cin >> s;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < 3; ++i){
        if(s[i] == t[i]){ans+=1;}
    }
    cout << ans;
    return 0;
}
