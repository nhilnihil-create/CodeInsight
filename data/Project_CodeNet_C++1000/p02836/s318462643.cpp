#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string S;
    cin>>S;
    int ans=0;
    if(S.size()==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;;i++){
        if(S.size()-1-i<i)break;
        if(S[i]!=S[S.size()-1-i])ans++;

    }
    cout<<ans<<endl;
    return 0;
}
