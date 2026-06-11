#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    string s; cin >> s;
    map<char,int> mp;
    for(int i = 0; i < 4; i++){
        mp[s[i]]++;
    }
    for(auto& x:mp){
        if(x.second != 2){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}