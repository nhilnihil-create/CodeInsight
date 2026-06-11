#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    cin >> word;
    
    if (word[word.size() - 1] == 's'){
        word = word + "es";
    }
    else {
        word = word + "s";
    }
    cout << word << endl;
}