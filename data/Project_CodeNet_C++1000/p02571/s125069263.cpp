#include <iostream>
using namespace std;

#include <string>
int main(){
    string s,t;cin >> s >> t;
    int maxi = 0;
    for(int i=0; i<s.size()-t.size()+1; i++) {
        int count = 0;
        for(int j=0; j<t.size(); j++) {
            if(s.at(i+j)==t.at(j)) count++;
        }
        maxi = max(maxi,count);
        if(maxi == t.size()) break;
    }
    cout << t.size()-maxi << endl;
}