#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    string s;
    cin>>n >>s;
    rep(i,s.length()){
        if(s[i]+n>'Z'){
            int a;
            rep(k,n){
                if(s[i]+k=='Z'){
                    a=n-k-1;
                }
            }
            printf("%c",('A'+a));
        }else{
            printf("%c",(s[i]+n));
        }
    }
}