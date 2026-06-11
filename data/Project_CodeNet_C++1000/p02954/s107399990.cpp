#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e5+5;
char s[maxm];
int a[maxm];
int n;
signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    int last=-1;
    for(int i=1;i<=n;i++){
        if(s[i]=='R')last=i;
        else{
            int t=(i-last)%2;
            if(t%2==0){
                a[last]++;
            }else{
                a[last+1]++;
            }
        }
    }
    last=-1;
    for(int i=n;i>=1;i--){
        if(s[i]=='L')last=i;
        else{
            int t=(last-i)%2;
            if(t%2==0){
                a[last]++;
            }else{
                a[last-1]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
/*

*/
