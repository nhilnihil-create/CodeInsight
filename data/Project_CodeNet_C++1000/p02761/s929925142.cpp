#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    if(n==1&&m==0){
        cout << 0 << endl;
        exit(0);
    }
    if(n==2&&m==0){
        cout << 10 << endl;
        exit(0);
    }
    if(n==3&&m==0){
        cout << 100 << endl;
        exit(0);
    }
    
    vector<char> ans(n+1,'x');
    int si;
    char ci;
    for (int i = 0; i < m; i++){
        cin >> si >> ci;
        if(ans[si]=='x' || ans[si]==ci){
            ans[si]=ci;
        }
        else{
            cout << -1 << endl;
            exit(0);
        }
    }
    if(n!=1&&ans[1]=='0'){
        cout << -1 << endl;
    }
    else{
        if(ans[1]=='x'){
            ans[1]='1';
        }
        for (int i = 1; i <= n; i++){
            if(ans[i]=='x'){
                ans[i]='0';
            }
            cout << ans[i];
        }
        cout << endl;
    }

}