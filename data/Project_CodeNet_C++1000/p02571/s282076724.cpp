#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    string S,T;
    cin>>S>>T;
    int ss=S.size();
    int ts=T.size();
    int ans=ts;
    for (int i=0;i<=ss-ts;i++){
        int yuuy=0;
        for (int k=0;k<ts;k++){
            if(S[i+k]!=T[k])yuuy++;
        }
        ans=min(ans,yuuy);
    }
    cout<<ans<<endl;
    return 0;
}
