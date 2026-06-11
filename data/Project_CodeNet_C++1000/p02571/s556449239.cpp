#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string t;
    int i, j;
    int temp, max;
    max = 0;
    cin >> s >> t;
    for(i = 0; i <= s.size() - t.size(); i ++){
        temp = 0;
        for(j = 0; j < t.size(); j ++){
            if(s[i + j] == t[j]){
                temp ++;
            }
        }
        if(max<temp){
            max = temp;
        }
    }
    cout << t.size() - max << endl;
    return 0;
}