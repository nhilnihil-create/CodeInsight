#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)

int main() {
    string S;
    cin >> S;
    int ans=1;
    string mae="AAA";
    while (S.size()!=0){
        if(S.substr(0,1)!=mae){
            mae=S.substr(0,1);
            S=S.substr(1);
            ans++;
        }else{
            if(S.size()==1){
                ans--;
                break;
            }else{
                mae=S.substr(0,2);
                S=S.substr(2);
                ans++;
            }
        }
    }
    if(S.size()==0){
        ans--;
    }
    cout << ans <<endl;
}