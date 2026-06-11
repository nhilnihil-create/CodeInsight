#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool found = true;
    if(n&1){
        cout << "No" << endl;
    }else{
        //int mid = n/2;
        int x = 0, y = n/2;
        while(x < n/2 && y < n){
            //cout << s[x] << " " <<s[y] << endl;
            if(s[x] != s[y]){
                found = false;
                cout << "No" << endl;
                break;
            }
            x++, y++;
        } 
        
        if(found)cout << "Yes" << endl;
        
    }
    
}
