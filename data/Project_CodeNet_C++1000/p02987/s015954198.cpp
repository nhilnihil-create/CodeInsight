#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    map<char,int> m;

    for(auto x:  s){
        if(m.find(x)==m.end()){
            m[x]=0;
        }else{
            m[x]++;
        }
    }
    int c = 0;
    for(auto i:m){
        c = max(c,i.second+1);
    }
    if(c == 2 && m.size() == 2){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
