#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char ch;
    int num;
    int counter[26] = {};
    while(cin >> ch) {
        
        
        // if(num < 0) continue;
        if(!isalpha(tolower(ch)))continue;
        num = tolower(ch) - 'a';
        // cout << "NUM " << num << " CH " << (char)tolower(ch) <<endl;
        counter[num] += 1;
        
        
    }
    
    for (int i = 0; i < 26; i++) {
        cout << (char)(i + 'a') <<   " : " << counter[i] << endl;
    }
    
    return 0;
}