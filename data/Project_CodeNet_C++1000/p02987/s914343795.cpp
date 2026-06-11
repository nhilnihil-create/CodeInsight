#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    int flag = 0;
    cin >> s;
    sort(s.begin(),s.end());
    if(s[0]==s[1] && s[2]==s[3] && s[0]!=s[2]) 
      cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}