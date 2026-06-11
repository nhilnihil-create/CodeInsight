#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

bool kaibun(string s){
    bool ans = true;
    rep(i,s.size()/2+1){
        if(s[i]!=s[s.size()-1-i]){
            ans = false;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    string a,b;
    a=s.substr(0,(s.size()-1)/2);
    b=s.substr((s.size()+3)/2-1,(s.size()-1)/2);
    if(kaibun(s)&&kaibun(a)&&kaibun(b)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}