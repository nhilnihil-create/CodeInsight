#include<iostream>
using namespace std;
int main(){
    int i,m,N,K,p[1000],tmp,sum=0;
    cin >> N >> K;
    for(i=0;i<N;++i){
        cin >> p[i];
    }
    for(i=0;i<N;++i){
        for(m=0;m<N;++m){
            if(p[m]>=p[i]){
                tmp=p[m];
                p[m]=p[i];
                p[i]=tmp;
            }
        }
    }
    for(i=0;i<K;++i){
        sum+=p[i];
    }
    cout << sum << endl;

    

    

}