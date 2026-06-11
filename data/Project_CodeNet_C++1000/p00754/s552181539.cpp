#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define vi vector<int>
#define pb(a) push_back(a)
#define all(a) (a).begin(), (a),end()
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    string inp;
    while(getline(cin, inp)){
        if(inp.size() == 1 && inp[0] == '.') break;
        string str;
        rep(i,inp.size()){
            if(inp[i] == '(' || inp[i] == ')' || inp[i] == '[' || inp[i] == ']'){
                str+=inp[i];
            }
        }
        while(str.size()){
            string copy = str;
            rep(i,str.size() - 1){
                if((str[i] == '(' && str[i + 1] == ')') || (str[i] == '[' && str[i + 1] == ']')){ 
                    str.erase(i,2);
                    break;
                }
            }
            if(copy == str) break;
        }
        if(str.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}