#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
#define REP(i, j) for(int i = 0; i < j; i++)
#define FOR(i, j, k) for(int i = j; i < k; i++)

int search(vector<char> &v, char c){
    for(int i = v.size() - 1; i >= 0; i--){
        if(v[i] == c){
            int a = 0, b = 0;
            FOR(j, i + 1, v.size()){
                if(v[j] == '(') a++;
                else if(v[j] == '[') b++;
                else if(v[j] == ')'){
                    if(a <= 0) return -1;
                    else a--;
                }
                else if(v[j] == ']'){
                    if(b <= 0) return -1;
                    else b--;
                }
            }
            if(a == 0 && b == 0) return i;
            else return -1;
        }
    }
    return -1;
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == ".") break;
        bool OKflg = true;
        vector<char> v;
        REP(i, str.length()){
            if(str[i] == '(') v.push_back('(');
            else if(str[i] == '[') v.push_back('[');
            else if(str[i] == ')'){
                int tmp = search(v, '(');
                if(tmp == -1){
                    OKflg = false;
                    break;
                } else REP(j, v.size() - tmp + 1) v.pop_back();
            }
            else if(str[i] == ']'){
                int tmp = search(v, '[');
                if(tmp == -1){
                    OKflg = false;
                    break;
                } else REP(j, v.size() - tmp + 1) v.pop_back();
            }
        //debug
        //REP(i, (int)(v.size())) cout <<v[i] <<", "; cout <<endl;
        }
        if(OKflg && v.size() == 0) cout <<"yes" <<endl;
        else cout <<"no" <<endl;
    }
    return 0;
}