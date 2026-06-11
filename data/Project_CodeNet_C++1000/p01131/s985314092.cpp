#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
    vector<string> k{".,!? ", "abc", "def",
                     "ghi"  , "jkl", "mno",
                     "pqrs" , "tuv", "wxyz"};
    int n;
    cin >> n; cin.ignore();
    while(n--){
        string line;
        getline(cin, line);
        int button = -1, push = -1;
        for(char c: line){
            if(c == '0'){
                if(button == -1)continue;
                cout << k[button][push % (int)k[button].size()];
                button = push = -1;
            }
            else{
                button = c - '1';
                push++;
            }
        }
        cout << '\n';
    }
    return 0;
}