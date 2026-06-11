#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100002;
long long ans[MAXN]={0};
int num[13]={0};
int maxlen;
long long getnum(){
    long long ret=0;
    for(int i=maxlen;i>=0;i--)
        ret=ret*10+num[i];
    return ret;
}
void op(){
    for(int i=0;i<=maxlen;++i){
        if(i==maxlen||num[i]<=num[i+1]){
            int check = 0 ;
            num[i]++;
            while(num[i]>9){
                num[i+1]++;
                num[i]=0;
                i++;
            }
            maxlen = max(maxlen,i);
            int j;
            while(i<maxlen&&abs(num[i]-num[i+1])>1){
                i++;
                num[i]++;
            }
            for(int j=i-1;j>=0;j--)
                num[j]=max(num[j+1]-1,0);
            return ;
        }
    }
}

void solve(){
    maxlen=0;
    num[0]=1;
    for(int i=1;i<MAXN;i++){
        ans[i]=getnum();
        op();
    }
}
int main()
{
    solve();
    int k;
    cin >> k;
    cout << ans[k] << endl;
    return 0;
}
