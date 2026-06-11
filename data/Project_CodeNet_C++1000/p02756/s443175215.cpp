#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;

    vector <string> ans(400100);
    int r = 200050;
    ans[200049] = s;
    int l = 200048;

    int rev = 0;

    rep(i,q){
        int a;
        cin >> a;
        if(a == 1){
            rev ++;
        }
        if(a == 2){
            int f;
            string c;
            cin >> f >> c;
            if(f == 1){//front
                if(rev % 2 == 0){
                    ans[l] = c;
                    l--;
                }
                else{
                    ans[r] = c;
                    r++;
                }
            }
            else{//back
                if(rev % 2 == 0){
                    ans[r] = c;
                    r++;
                }
                else{
                    ans[l] = c;
                    l--;
                }
            }
        }
    }
    
    if(rev%2==1){
        reverse(all(ans[200049]));
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i];
        }
    }
    else{
        for(int i=0; i<ans.size(); i++){
            cout << ans[i];
        }
    }
}