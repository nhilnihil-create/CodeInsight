#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    string t;
    cin >> s >> t;

    int min = t.size();
    for(int i=0; i<=s.size()-t.size(); i++){
        string ss = s.substr(i, t.size());
        int m = 0;
        for(int j=0; j<ss.size(); j++){
            if(ss[j]!=t[j]){
                m++;
            }
        }
        if(min>m)  min = m;
    }

    cout << min << endl;
    return 0;
}