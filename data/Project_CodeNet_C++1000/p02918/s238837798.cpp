#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e6+5;
char s[maxm];
int n,k;
signed main(){
    cin>>n>>k;
    scanf("%s",s+1);
    int ans=0;
    vector<int>rl,lr;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1]){
            ans++;
        }else{
            if(s[i]=='L'){
                rl.push_back(i);
            }else{
                lr.push_back(i);
            }
        }
    }
    int len1=rl.size();
    int len2=lr.size();
    int c=0,cc=0;
    vector<int>temp;
    while(c<len1&&cc<len2&&k){
        int x=rl[c],y=lr[cc];
        if(x<y){//R|LLL|R
            ans+=2;
            k--;
            c++,cc++;
        }else{//L|RRR|L
            ans+=2;
            k--;
            c++,cc++;
        }
    }
    while(c<len1)temp.push_back(rl[c++]);
    while(cc<len2)temp.push_back(lr[cc++]);
    ans+=min((int)temp.size(),k);
    cout<<ans<<endl;
    return 0;
}
/*
LLL这种全部一样的翻转之后权值不变,
只有R|LLL这种,翻转一遍之后会增加一个权值,
遇到R|LLL|R这种能增加两个权值.
其他情况下不增加了.
发现一次操作最多增加两个权值.
那么贪心一下就行了:
记录每个L|R和R|L的位置,然后贪心的翻转.
*/
