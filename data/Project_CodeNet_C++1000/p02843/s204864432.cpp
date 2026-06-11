#include <bits/stdc++.h>
using namespace std;
int x,p,q;
bool dfs(int i,int k,int sum){//iは買った個数（そのまま上3桁に直結）,kは現在目をつけている品物、sumは下3桁の合計額
    if(i==q)return p==sum;
    
    for(int j=k;j<=5;j++){
        if(dfs(i+1,j,sum+j))return true;
    }
    return false;
}
int main(void){
    cin>>x;
    p = x%100;//pは下3桁
    q = x/100;//qは上3桁
    //cout<<p<<q<<endl;
    bool res = dfs(0,0,0);
    if(res)cout<<"1"<<endl;
    else cout<<"0"<<endl;
}
