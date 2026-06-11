#include <iostream>

using namespace std;

int main(){
    string s; cin >> s;
    char cur = 'h';
    if(s.length()%2!=0){
        cout << "No\n"; return 0;
    }
    for(auto c: s){
        if(c!=cur){
            cout << "No\n"; return 0;
        }
        cur = (cur=='h') ? 'i' : 'h';
    }
    cout << "Yes\n";
    return 0;
}