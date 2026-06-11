#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0, j = s.size()-1; i < j; i++, j--){
        if(s[i] != s[j]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}