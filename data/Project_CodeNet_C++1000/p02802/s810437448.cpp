#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    int ac;
    int wa[200010]={0};
    bool flg[100010]={false};
    rep(i,m){
        int p;
        string s;
        cin>>p>>s;
        p--;
        if(flg[p]) continue;
        else{
            if(s=="AC"){
                ac++;
                flg[p]=true;
            }
            else wa[p]++;
        }
    }
    int WA;
    rep(i, n){
        if(flg[i]) WA+=wa[i];
    }
    cout<<ac<<" "<<WA<<endl;
}