//D
#include<bits/stdc++.h>
using namespace std;
int n;
char line[20];
int cnt[26];

void dfs(int u){
    int i,mx;
    if(u==n) {
            for(i=0;i<n;i++) cout<<line[i];
            puts("");
            return;
    }
    for(i=0;i<26;i++) {
        if(cnt[i]) mx=i;}
    for(i=0;i<=mx+1;i++){
            //cout<<mx+1<<endl;
            line[u]='a'+i;
            cnt[line[u]-'a']++;
            dfs(u+1);
            cnt[line[u]-'a']--;
    }
}
int main(){
    cin>>n;
    line[0]='a';
    cnt[0]=1;
    dfs(1);
}

