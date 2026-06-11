#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;

string toUpper(string s);

int main(){
    string target, source;
    cin >> target;
    target = toUpper(target);
    
    int cnt=0;
    
    while(1){
        cin >> source;
        if(source=="END_OF_TEXT") break;
        source = toUpper(source);
        if(target==source) cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}

string toUpper(string s){
    string t = s;
    for(int i=0; i < s.size(); i++){
        t[i] = toupper(s[i]);
    }
    return t;
}