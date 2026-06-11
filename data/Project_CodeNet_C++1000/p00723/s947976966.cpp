#include <iostream>
#include <string>
#include <set>

using namespace std;

#define rall(c) (c).rbegin(), (c).rend()

int main(){
    int m;
    cin >> m;
    while(m--){
        string tr;
        cin >> tr;
        set<string> org;
        for(int i=1; i<(int)tr.size(); ++i){
            string s = tr.substr(0, i), t = tr.substr(i);
            string rs = string(rall(s)), rt = string(rall(t));
            org.insert(s + t);
            org.insert(t + s);
            org.insert(rs + t);
            org.insert(t + rs);
            org.insert(s + rt);
            org.insert(rt + s);
            org.insert(rs + rt);
            org.insert(rt + rs);
        }
        cout << org.size() << '\n';
    }
    return 0;
}