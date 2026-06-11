#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int A,B,C;
    cin>>A>>B>>C;
    int X=A-B;
    int ans=C-X;
    if(ans<0){
        ans=0;
    }
    cout<<ans<<endl;
    
}
