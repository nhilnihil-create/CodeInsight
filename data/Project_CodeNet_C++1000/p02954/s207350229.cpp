#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    vector<int> ans(s.size());
    int change;//左端のL
    int x=1;//LまでのRの数
    int y=1;//Lの数
    for(int i = 1; i < s.size(); i++) {
        if(s[i-1]=='R' && s[i]=='R'){
            x++;
        }
        if(s[i-1]=='R' && s[i]=='L'){
            change = i;
        }
        if(s[i-1]=='L' && s[i]=='L'){
            y++;
        }
        if(s[i-1]=='L' && s[i]=='R'){
            if((x+y)%2==0){
                ans[change-1]=(x+y)/2;
                ans[change]=(x+y)/2;
            }
            else{
                if(x%2==1){
                    ans[change-1]=(x+y)/2+1;
                    ans[change]=(x+y)/2;
                }
                else{
                    ans[change-1]=(x+y)/2;
                    ans[change]=(x+y)/2+1;
                }
            }
            x =1;
            y =1;
        }
    }
    
    if((x+y)%2==0){
        ans[change-1]=(x+y)/2;
        ans[change]=(x+y)/2;
    }
    else{
        if(x%2==1){
            ans[change-1]=(x+y)/2+1;
            ans[change]=(x+y)/2;
        }
        else{
            ans[change-1]=(x+y)/2;
            ans[change]=(x+y)/2+1;
        }
    }

    for(int i = 0; i < s.size()-1;i++) {
        cout << ans[i] << ' ';
    }
    cout << ans[s.size()-1] << endl;
    return 0;
}