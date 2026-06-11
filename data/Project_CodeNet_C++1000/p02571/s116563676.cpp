#include<iostream>
#include<cstring>

using namespace std;

const int N=1010;
char s[N];
char t[N];

int main(){
    scanf("%s",s);
    scanf("%s",t);
    int len1=strlen(s);
    int len2=strlen(t);
    int res=N;
    for(int i=0;i+len2<=len1;++i){
        int cnt=0;
        for(int j=0;j<len2;++j){
            if(t[j]!=s[i+j]) cnt++;
        }
        res=min(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}
