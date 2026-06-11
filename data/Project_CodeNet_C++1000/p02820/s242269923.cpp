#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,K; cin>>N>>K;
    ll R,S,P; cin>>R>>S>>P;
    string T; cin >>T;
    
    //高橋くんの出す手
    string taka="";
    ll ans=0;
    
    //int rl,sl,pl;
    rep(i,N){
        ll ik = i-K;
        bool ikflg = false;
        if(i-K>=0) ikflg = true;
        
        if(ikflg){
            if(T[i]=='r'){
                if(taka[ik]=='p'){
                    taka +='x';
                }else{
                    taka +='p';
                    ans +=P;
                }
            }
            
            if(T[i]=='s'){
                if(taka[ik]=='r'){
                    taka +='x';
                }else{
                    taka +='r';
                    ans +=R;
                }
            }
            if(T[i]=='p'){
                if(taka[ik]=='s'){
                    taka +='x';
                }else{
                    taka +='s';
                    ans += S;
                }
            }
            
        }
        
        if(!ikflg){
            if(T[i]=='r'){
                ans +=P;
                taka +='p';
            }
            if(T[i]=='s'){
                ans +=R;
                taka +='r';
            }
            if(T[i]=='p'){
                ans +=S;
                taka +='s';
            }
        }
        
    }
    
    //cout << taka << endl;
    cout << ans << endl;
}
