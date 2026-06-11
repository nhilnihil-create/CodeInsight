#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int A,B,C,ans;
    cin>>A>>B>>C;
    if(C-(A-B)>=0){
        ans=C-(A-B);
    }
    else{
        ans=0;
    }
    cout<<ans<<endl;
    return 0;
}
