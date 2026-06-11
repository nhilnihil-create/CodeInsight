#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    for(int i = 0; i  <s.size(); i++){
        if(i%2 == 0){
            if(!(s[i]=='R'||s[i]=='U'||s[i]=='D')){
                puts("No");
                return 0;
            }
        }
        else{
            if(!(s[i]=='L'||s[i]=='U'||s[i] == 'D')){
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}