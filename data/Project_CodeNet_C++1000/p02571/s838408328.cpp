#include <bits/stdc++.h>
using namespace std;
string s,t;
int ans;
int main()
{
    cin>>s>>t;
    int lens=s.length();
    int lent=t.length();
    for(int i=0;i<lens;i++){
        int tmp=0;
        for(int j=0;j<lent;j++){
            if(i+j<lens&&s[i+j]==t[j]){
                tmp++;
            }
            if(i+j>=lens)
                tmp=0;
        }
        ans=max(ans,tmp);
    }
    printf("%d",lent-ans);
    return 0;
}
