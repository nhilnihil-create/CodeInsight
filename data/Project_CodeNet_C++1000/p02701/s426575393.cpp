#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n, cnt = 0;
    string s;
    map<string, int> dict;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        dict[s];
    }

    cout << dict.size() << endl;

    return 0;
}