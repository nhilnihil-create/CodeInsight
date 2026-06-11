#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B;
    cin>>A>>B;
    int ans=1;
    int sum=A;
    if(B==1){
        cout<<0<<endl;
        return 0;
    }
    while(sum<B){
        sum+=A-1;
        ans++;
    }
    cout<<ans<<endl;
}