#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    int ans = 1;
    int flag = 0;

    for(int i = 1; i < n; i++){
        if(flag == 0){
            if(s[i] == s[i - 1]){
                flag = 1;
                i++;
                if(i < n){
                    ans++;
                }
            }else{
                ans++;
            }
        }else{
            flag = 0;
            ans++;
        }
    }

    cout << ans << endl;
}