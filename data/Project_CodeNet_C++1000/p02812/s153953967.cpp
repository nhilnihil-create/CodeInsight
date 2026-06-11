#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int MAXN=100100;
char s[1000];
bool check(int p){
    if(s[p]=='A' && s[p+1]=='B' && s[p+2]=='C') return 1;
    return 0;
}
int main()
{
    ios;
    int n,cnt=0;
    cin>>n;
    cin>>s+1;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        if(s[i]=='A'){
            if(check(i)){
                cnt++;
                i+=2;
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}