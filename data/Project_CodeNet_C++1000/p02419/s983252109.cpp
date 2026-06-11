#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string toUpper(string x){
    string y = x;
    for(int i=0;i<x.size();i++){
        y[i] = toupper(x[i]);
    }
    return y;
}

int main(){
    int cnt=0;
    string word,word2;
    cin >> word;
    word = toUpper(word);
    cin >> word2;
    while(1){
        if(word2=="END_OF_TEXT") break;
        word2 = toUpper(word2);
        if(word==word2) cnt++;
        cin >> word2;
    }
    cout << cnt << endl;
    return 0;
}
