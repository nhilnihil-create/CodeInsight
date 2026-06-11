#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;
    int K; cin>>K;

    int64_t ans;

    bool allSame=true;
    rep(i,0,S.size()) if(S.at(i)!=S.at(0)){allSame=false;break;}
    if(allSame){ans=S.size()*K/2;}
    else{
        int64_t val1=0;
        string _S=S;
        if(K>1) _S+=S;
        rep(i,1,_S.size()){
            if(_S.at(i-1)==_S.at(i)){
                _S.replace(i,1,".");
                val1++;
                i++;
            }
        }

        ans=val1;

        if(K>2){
            int64_t val2=0;
            _S=S+S+S;
            rep(i,1,_S.size()){
                if(_S.at(i-1)==_S.at(i)){
                    _S.replace(i,1,".");
                    val2++;
                    i++;
                }
            }
            ans+=(val2-ans)*(K-2);
        }
    }
    cout<<ans<<endl;
}