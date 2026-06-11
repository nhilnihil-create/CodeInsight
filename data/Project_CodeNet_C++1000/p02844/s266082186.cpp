#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string pin = "";
int ans = 0;
void checkPin(){
    //cout << pin << endl;
    int pin0 = -1;
    int pin1 = -1;
    int pin2 = -1;
    for(int i = 0; i < n; i++){
        if(pin0==-1){
            if(pin[0]==s[i]){
                pin0=i;
            }
        }else if(pin1==-1){
            if(pin[1]==s[i]){
                pin1=i;
            }
        }else if(pin2==-1){
            if(pin[2]==s[i]){
                pin2=i;
                //cout << pin << endl;
                ans++;
                break;
            }
        }else{
            break;
        }
    }    
}
void dfs(int digit){
    char c = '0';
    if((0<=digit)&&(digit<=9)){
        c+=digit;
    }
    pin+=c;
    if(pin.length()>=3){
        checkPin();
        return;
    }else{
        for(int i = 0; i <= 9; i++){
            dfs(i);
            pin.pop_back();
        }
    }
}
int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i <= 9; i++){
        dfs(i);
        pin.pop_back();
    }
    cout << ans << endl;
    return 0;
}