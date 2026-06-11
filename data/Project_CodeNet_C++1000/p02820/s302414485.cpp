#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    int t=1;
    //cin >> t;
    while(t--){
        int n,k,r,s,p,i,j,cnt=0;
        cin >> n >> k >> r>>s >> p;
        string st;
        cin >> st;
        int roc[n+1],pap[n+1],sis[n+1];
        memset(roc,0,sizeof(roc));
        memset(sis,0,sizeof(sis));
        memset(pap,0,sizeof(pap));
        for(i=0;i<st.size();i++){
            if(i==0){
                if(st[i]=='r'){
                    cnt+=p;
                    pap[i]=1;
                }if(st[i]=='s'){
                    cnt+=r;
                    roc[i]=1;
                }if(st[i]=='p'){
                    cnt+=s;
                    sis[i]=1;
                }
            }else{
                if(i-k>=0&&st[i]==st[i-k]){
                    //f=0;
                    if(st[i]=='r' && pap[i-k]==1){
                        pap[i-k]=0;
                    }else if(st[i]=='r'){
                        cnt+=p;
                        pap[i]=1;
                    }
                    if(st[i]=='s' && roc[i-k]==1){
                        roc[i-k]=0;
                    }else if(st[i]=='s'){
                        cnt+=r;
                        roc[i]=1;
                    }
                    if(st[i]=='p' && sis[i-k]==1){
                        sis[i-k]=0;
                    }else if(st[i]=='p'){
                        cnt+=s;
                        sis[i]=1;
                    }
                }else{
                    if(st[i]=='r'){
                    cnt+=p;
                    pap[i]=1;
                }if(st[i]=='s'){
                    cnt+=r;
                    roc[i]=1;
                }if(st[i]=='p'){
                    cnt+=s;
                    sis[i]=1;
                }
                }
            }
        }
        cout << cnt << endl;
        
    }
}