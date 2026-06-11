#include <iostream>
using namespace std;
int main(void){
    int K,i;
    int k=7;
    cin>>K;
    for(i=1;i<=K;i++){
        if(k%K==0){
            cout<<i;
            break;
        }
        k=(k*10+7)%K;
    }
    if(K<i){
        cout<<-1;
    }
}
