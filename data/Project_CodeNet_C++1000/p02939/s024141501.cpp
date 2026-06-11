#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    int ans=0;
    char pre=' ';
    int cur=0;
    for(int i=0; i<str.size(); i++) {
        if(pre==' ') {
            ans++;
            cur=1;
            pre=str[i];
        } else if(pre==str[i]) {
            if(i+1<str.size()) {
                pre=' ';
                cur=0;
                ans++;
            }
            i++;
        } else {
            ans++;
            cur=1;
            pre=str[i];
        }
    }
    
    cout << ans << endl;


    return 0;
    
}