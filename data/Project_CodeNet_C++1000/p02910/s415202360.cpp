#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin >> s;
    int flag = 0;
    for(int i=0; s[i]!='\0'; i++){
       if(i%2){
           if(s[i]!='L' && s[i]!='U' && s[i]!='D') flag = 1;
       }
       else{
           if(s[i]!='R' && s[i]!='U' && s[i]!='D') flag = 1;
       }

    }
    if(flag==0)
    cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}