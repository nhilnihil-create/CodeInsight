#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

int main(){
    int N;
    string S;
    int ans=0;
    cin>>N>>S;
    
    for (int i=0;i<=999;i++){
        int c[3]={i/100,(i/10)%10,i%10};
        int f=0;
        for (int j=0;j<N;j++){
           //cout<<S[j]<<" "<<c[f]<<endl;
            if(S[j]==('0'+c[f])) f++;//'0'は文字コード、数値としては48になる。つまりS[j]の中身の文字コード(数値）とc[f]の文字コード(数値)を比較している。
            if(f==3) break;
        }
        if (f==3) ans++;
    }
    cout<<ans<<endl;
    return 0;
}