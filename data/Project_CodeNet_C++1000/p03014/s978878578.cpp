#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int h,w;
char s[2005][2005];
int ho[2005][2005];
int vi[2005][2005];
int ans;
int main(void){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                if(j==0){
                    ho[i][j]=1;
                }else{
                    ho[i][j]=ho[i][j-1]+1;
                }
            }else{
                ho[i][j]=0;
            }
        }
        for(int j=w-1;j>=0;j--){
            if(ho[i][j+1]>0&&s[i][j]=='.') ho[i][j]=ho[i][j+1];
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(s[j][i]=='.'){
                if(j==0){
                    vi[j][i]=1;
                }else{
                    vi[j][i]=vi[j-1][i]+1;
                }
            }else{
                vi[j][i]=0;
            }
        }
        for(int j=h-1;j>=0;j--){
            if(vi[j+1][i]>0&&s[j][i]=='.') vi[j][i]=vi[j+1][i];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.') ans=max(ans,ho[i][j]+vi[i][j]-1);
        }
    }
    cout<<ans<<endl;
    
}
