#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
int main(){
    int n;
    string str;
    cin >> n >> str;
    vector<char> cs{str.at(0)};
    int count=1;
    for(int i=1; i<n; i++) {
        if(cs.at(count-1)!=str.at(i)){
            cs.push_back(str.at(i));
            count++;
        }
    }
    cout << cs.size() << endl;
}