#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d >> s;
    s = "#" + s + "#";
    auto can_reach = [&](int start, int end) {
        for (int i = start; i + 1 <= end; i++) {
            if (s[i] == '#' && s[i + 1] == '#') return false;
        }
        return true;
    };
    if(!can_reach(a,c)||!can_reach(b,d)){
         cout << "No" << endl;
         return 0;
    }
    if(d<c){
        int flag = 0;
        for(int i=b;i<=d;i++){
            if(s[i-1]==s[i]&&s[i]==s[i+1]&&s[i]=='.'){
                flag = 1;
            }
        }
        if(!flag){
        cout << "No" << endl;
        return 0;
        }
    }
    cout << "Yes" << endl;
}