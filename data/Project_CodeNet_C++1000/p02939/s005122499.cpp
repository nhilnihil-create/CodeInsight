#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    string past="",now="";
    int count=0;
    for (int i=0;i<s.size();i++) {
        if (i==0) {
            past+=s[i];
            count++;
        } else {
            now+=s[i];
            if (past!=now) {
                past=now;
                count++;
                now="";
            }
        }
    }
    cout<<count<<endl;
}