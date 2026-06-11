#include <bits/stdc++.h>
using namespace std;
string s;
long long ans;
int main()
{
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        long long l=0;
        long long r=0;
        while(i<len&&s[i]=='<'){
            l++;
            i++;
        }
        while(i<len&&s[i]=='>'){
            r++;
            i++;
        }
        i--;
        if(l>=r){
            ans+=((l+1)*l)/2;
            r--;
            ans+=((r+1)*r)/2;
        }else{
            ans+=((r+1)*r)/2;
            l--;
            ans+=((l+1)*l)/2;
        }
    }
    printf("%lld",ans);
    return 0;
}