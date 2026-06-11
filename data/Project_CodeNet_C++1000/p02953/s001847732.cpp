#include <iostream>
#define rep(i,n)  for(int i=0;i!=(n);++i)

using namespace std;

typedef long long ll;

int main(){
    int N;
    scanf("%d",&N);
    ll H[N];

    rep(i,N)scanf("%lld",H+i);

    ll h=H[0]-1;
    bool flag=true;

    for(int i=0;i!=N-1;++i){
        if(h<=H[i+1]-1){
            h=H[i+1]-1;
        }else if(h<=H[i+1]){
            h=H[i+1];
        }else{
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    



}