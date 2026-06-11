#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N,D;
    cin>>N>>D;
    int A=2*D+1;
    int ans=N/A;
    if(N%A!=0){
        ans++;
    }
    cout<<ans<<endl;
}
