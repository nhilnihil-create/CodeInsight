#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++) ;
int main() {
    ll L,R;
    cin>>L>>R;
    if(R-L>=2019){
        cout<<0<<endl;
    }
    else{
    if(L%2019>R%2019){
        L=L%2019;
        R=R%2019+2019;
    }
    else
    {
        L=L%2019;
        R=R%2019;
    }
    ll answer=100000;
    for(int i=L; i<R+1; i++){
        for(int j=L; j<R+1; j++){
            if(i==j){
                continue;
            }
            else if(i*j%2019<answer){
                answer=i*j%2019;
            }
        }
    }
    cout<<answer<<endl;
    }
}
