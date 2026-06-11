#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl

int main(){
    int A, B; cin>>A>>B;
    for(int i=0; i<=1000; i++){
        if(i*8/100 == A && i/10==B){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
}
