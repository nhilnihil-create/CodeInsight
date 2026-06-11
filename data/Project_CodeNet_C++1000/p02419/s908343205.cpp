#include <iostream>
#include <string>

using namespace std;
const string EOT = "END_OF_TEXT";

void to_lower_string(string& str);

int main(){
    string w;
    cin >> w;
    to_lower_string(w);
    string t;
    int counter = 0;
    while(cin >> t){
        to_lower_string(t);
        if(t == w){
            ++counter;
        }
    }
    cout << counter <<endl;
}

void to_lower_string(string& sTr){
    for(auto &c : sTr){
        c = tolower(c);
    }
}