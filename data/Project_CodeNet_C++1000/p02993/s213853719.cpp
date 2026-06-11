#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    string s; cin >> s;
    char now = s[0];
    for(int i=1; i<s.size(); i++){
        if(s[i]==now){
            cout << "Bad" << endl;
            return 0;
        }else{
            now = s[i];
        }
    }
    cout << "Good" << endl;
}