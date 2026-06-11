#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    int ls, lt, cnt=0;
    cin >> s >> t;
    ls = s.size();
    lt = t.size();
    if(ls==lt-1){
        for(int i=0; i<ls; i++){
            if(s[i]==t[i]) ++cnt;
        }
        if(cnt==ls) cout << "Yes\n";
        else cout << "No\n";
    }else{
        cout << "No\n";
    }
    return 0;
}
