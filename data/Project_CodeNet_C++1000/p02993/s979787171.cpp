#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int flag=1;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]) flag = 0;
    }
    if(flag) cout << "Good" << endl;
    else cout << "Bad" << endl;
}
