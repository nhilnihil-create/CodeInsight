#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
 #define rep(i, n) for (int i = 0; i < (int)(n); i++)
 #define big 1000000007
int main(){
    int n,a,b,c,d;
    cin >> n>>a>>b>>c>>d;
    a -=1,b-=1,c-=1,d-=1;
    string s;
    cin>>s;
    bool ans=true;
    //まず単独で判定    
    for(int i=a;i<c;i++){
        if(s[i]=='#'&& s[i+1]=='#'){
            ans = false;
        }
    }
    for(int i=b;i<d;i++){
        if(s[i]=='#'&& s[i+1]=='#'){
            ans = false;
        }
    }
    if(ans){//ここから両方
        if(b<d&&d<c){
            bool three =false;
            for(int x=b;x<=d;x++){
                if(s[x-1]=='.'&&s[x]=='.'&&s[x+1]=='.'){
                    three = true;
                }
            }
            if(!three){
                ans = false;
            }
        }
    }

    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}