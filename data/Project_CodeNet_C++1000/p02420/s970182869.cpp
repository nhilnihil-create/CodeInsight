#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    double pai=3.141592653589;
    int m,h,l;
    char s[200];
    string ans,tmp1,tmp2;
    for(;;){
        scanf("%s",&s);
        tmp1=s;
        if(tmp1=="-"){
            break;
        }
        scanf("%d",&m);
        l=tmp1.length();
        for(int i=0;i<m;i++){
            scanf("%d",&h);
            ans="";
            ans.assign(tmp1,h,l-h+1);
            tmp2.assign(tmp1,0,h);
            ans+=tmp2;
            tmp1=ans;
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}
