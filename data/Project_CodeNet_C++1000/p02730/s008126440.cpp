#include<iostream>
#include<string>
using namespace std;

bool is_palindrome(string w){
    size_t b=0, e=w.size()-1;
    bool flag = 1;
    for(size_t i=0; i<w.size()/2; i++){
        if(w[b] != w[e]){
            flag = 0;
            break;
        }
        b++;
        e--;    
    }
    return flag;
}

int main(){
    string in;
    cin >> in; 
    string in_1 = in.substr(0,in.length()-((in.length()-1)/2)-1); 
    string in_2 = in.substr(((in.length()+3)/2)-1); 
    if(is_palindrome(in) && is_palindrome(in_1) && is_palindrome(in_2)){
        cout << "Yes";
    }
    else cout << "No";
}