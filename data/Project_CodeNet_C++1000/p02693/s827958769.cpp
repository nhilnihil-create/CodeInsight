#include <iostream>
 
using namespace std;
 
int main(){
    int K,A,B;
    cin>>K>>A>>B;
    for(int i=A;i<=B;i++){
        if(i%K==0){
            printf("OK\n");
            break;
        }else if(i==B)printf("NG\n");
    }
}