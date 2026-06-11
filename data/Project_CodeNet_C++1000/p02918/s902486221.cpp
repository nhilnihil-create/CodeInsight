#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
int n,k;
char s[100010];
int LR,RL;
int ans=0;

void swap(){
    int tem=LR;
    LR=RL;
    RL=tem;
}

int main(){
    scanf("%d%d%s",&n,&k,s);
    for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) ans++;
    for(int i=1;i<n && k>0;i++){
        if(s[i-1]=='R' && s[i]=='L'){
            if(LR>0 && (i-2<0 || s[i-2]=='R')){
                LR--;
                swap();
                ans+=2;
                k--;
            }
            else RL++;
        }
        else if(s[i-1]=='L' && s[i]=='R'){
            if(RL>0 && (i-1<0 || s[i-1]=='L')){
                RL--;
                swap();
                ans+=2;
                k--;
            }
            else LR++;
        }
    }
    ans+=min(k,LR+RL);
    cout<<ans<<endl;
    return 0;
}
