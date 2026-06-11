#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    int N;
    cin>>N;
    if(__builtin_popcount(N)==1){
        cout<<"No"<<endl;
        return 0;
    }else{
        cout<<"Yes"<<endl;
    }
    cout<<1<<' '<<2<<endl;
    for(int i=2;i<N;i+=2){
        cout<<i<<' '<<i+1<<endl;
        cout<<i+1<<' '<<1+N<<endl;
        cout<<1+N<<' '<<i+N<<endl;
        cout<<i+N<<' '<<i+1+N<<endl;
    }
    if(N%2==0){
        int y=1;
        while(y<=N)y<<=1;
        y>>=1;
        int x=N^y^1;
        cout<<x<<' '<<N<<endl;
        cout<<y+N<<' '<<2*N<<endl;
    }
    return 0;
}
