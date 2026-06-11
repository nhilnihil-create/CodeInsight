#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int n;
    cin>>n;
    for(int i=1;i<=50000;i++){
        if((i*108)/100==n){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<":("<<endl;
    
    
}
