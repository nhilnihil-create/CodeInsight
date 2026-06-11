#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int ans = 0, count = 0;
    for(char c : s){
        if(c == 'R'){
            count++;
          	ans = max(ans, count);
        }else if(c == 'S'){
            count = 0;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}