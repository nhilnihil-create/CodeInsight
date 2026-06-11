#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    t=1;
    while(t--){
        string s;
        cin >> s;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            ans=(ans%9+(s[i]-'0')%9)%9;
            
        }
        if(ans == 0)cout << "Yes" << endl;
            else{
                cout << "No"<< endl;
            }
    }
}