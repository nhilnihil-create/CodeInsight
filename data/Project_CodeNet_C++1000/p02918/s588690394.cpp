#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,K; cin>>N>>K;
    string S; cin>>S;
    
    char c=S.front();
    bool mismatch=false;
    int _k=0;
    rep(i,0,N){
        if(c!=S.at(i)){
            if(_k<K){
                S.at(i)=c;
                if(mismatch){

                }else{
                    mismatch=true;
                }
            }
        }else{
            if(mismatch){
                _k++;
                mismatch=false;
            }else{

            }
        }
    }

    int ans=0;
    rep(i,1,N){
        if(S.at(i)==S.at(i-1)){
            ans++;
        }
    }

    cout<<ans<<endl;
}