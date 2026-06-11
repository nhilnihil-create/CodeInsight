#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
using namespace std;
ll MAX=1e18;

int main(){
    int N;
    cin>>N;
    ll A[N],ans=1;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0){
            cout<<"0"<<endl;
            return 0;
        }
    }
    for(int i=0;i<N;i++){
        if(A[i]<=MAX/ans) ans*=A[i];
        else{
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}