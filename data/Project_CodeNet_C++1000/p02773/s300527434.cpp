#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> word;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        if(word.count(str)){
            word.at(str) ++;
        }else{
            word[str] = 1;
        }
    }
    int m = 0;
    for(auto x:word){
        if(m < x.second) m = x.second;
    }
    for(auto x:word){
        if(x.second == m) cout << x.first << endl;
    }
}