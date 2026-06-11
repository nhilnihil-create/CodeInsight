#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++) ;
int main() {
ll X;
cin>>X;
for(ll i=-200; i<200; i++){
    for(ll j=-200; j<200; j++){
        if(i*i*i*i*i-j*j*j*j*j==X){
            cout<<i<<" "<<j<<endl;
            i+=500;
          j+=500;
        }
    }
}

}
