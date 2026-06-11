#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    string s;
    map<char,int> map{};
    cin >> s;
    
    for(int i=0;i<4;i++){
        map[s[i]] = 1;
    }
    
    if(map.size() == 2){
        cout << "Yes" <<endl;   
    }
    else{
        cout << "No" <<endl;
    }
}