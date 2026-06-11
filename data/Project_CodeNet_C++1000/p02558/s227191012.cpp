#include <iostream>
#include <string>
#include <vector>
#include <atcoder/dsu>
using ll=long long;
using namespace std;
using namespace atcoder;

int main(){
    int N,Q;
    cin>>N>>Q;
    dsu d(N);
    int a,b,c;
    for(int i=0;i<Q;i++){
        cin>>a>>b>>c;
        if(a){
            if(d.same(b,c)){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }else{
            d.merge(b,c);
        }
    }

    return 0;
}