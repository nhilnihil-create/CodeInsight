#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    string operation, target;
    typedef unordered_set<string> set_t;
    set_t dict;
    for(int i=0;i<n;i++){
        cin >> operation >> target;
        if(operation == "insert"){
            dict.insert(target);
        }
        else{
            if(dict.count(target)==0)
                cout << "no" << endl;
            else
                cout << "yes" << endl;
        }
    }
}