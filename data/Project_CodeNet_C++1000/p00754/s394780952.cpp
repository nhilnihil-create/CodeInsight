#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;


bool dfs(string s){
//    cout << "dfs :" << s << endl;
    if(s=="") return true;

    vector<string> vs;
    string ss;
    int a=0,b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') a++;
        else if(s[i]==')') a--;
        else if(s[i]=='[') b++;
        else if(s[i]==']') b--;
        ss += s[i];
        if(i!=0 && a==0 && b==0){
            vs.push_back(ss);
            ss="";
        }
    }

    if(a!=0 || b!=0){
//        cout << "a or b is not 0" << endl;
        return false;
    }

//    cout << " vs " << endl;
//    for(auto v : vs){
//        cout << v << endl;
//    }

    for(int i=0;i<vs.size();i++){
        string t = vs[i];
        char s = t[0];
        char e = t[t.size()-1];
        if(!((s=='('&&e==')')||(s=='['&&e==']'))){
//            cout << " not match " << endl;
            return false;
        }
        if(!dfs(t.substr(1,t.size()-2))){
//            cout << "dfs is not true" << endl;
            return false;
        }
    }
    return true;
}

void solve(string s){
    string ss;
    for(char c : s) if(c=='[' || c==']' || c=='(' || c==')') ss += c;

//    cout << ss << endl;
    bool f = dfs(ss);
    if(f) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main(){
    string s;
    while(getline(cin,s)){
        if(s==".") break;
        solve(s);
    }
}