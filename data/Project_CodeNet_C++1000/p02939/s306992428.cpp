#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    vector<string> p;
    string t;
    p.push_back(t);
    p[0] += s[0];
    p.push_back(t);
    
    for(int i=1; i<s.size(); i++){
        p[p.size()-1]+= s[i];
        if(p[p.size()-1]==p[p.size()-2]){
            if(i==(int)s.size()-1){
                p.pop_back();
                p[p.size()-1]+= s[i];
            }
            else continue;
        }
        else{
            p.push_back(t);
        }
    }
    if(p[p.size()-1]==t)
        p.pop_back();
    
    cout << p.size() << endl;
    
    return 0;
}