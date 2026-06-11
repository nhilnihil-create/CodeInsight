#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n;cin>>n;
    ll rj=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            rj+=j;
        }
    }
    cout <<rj<<endl;
}
