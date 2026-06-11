//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    int minn = INT_MAX;
    string s,t;
    int i,j,len,len2,p,cnt = 0;
    cin >> s >> t;
    len = s.size();
    len2 = t.size();
    for(i = 0;i<=(len - len2);i++){
        p = i;
        for(j = 0;j<len2;j++){
            if(t[j] != s[p++]) cnt++;
        }
        minn = min(minn,cnt);
        cnt = 0;
    }
      cout << minn << endl;
    return 0;
}