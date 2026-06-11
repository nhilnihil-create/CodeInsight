#include <bits/stdc++.h>

using namespace std;


int main(void) {
    long long A,B,ans=-1;

    cin>>A>>B;

    for(int i=1;i<=10000;i++){
        if(int(0.08*i) == A && int(0.10*i) == B){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;



	return 0;
}