#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N;
    cin>>N;
    int a;
    int flag=0;
    for(int i=0;i<N;i++){
        cin>>a;
        if(a%2==0){
            if(a%3==0||a%5==0){

            }else{
                flag=1;
            }
        }
    }
    if(flag){
        cout<<"DENIED"<<endl;
    }else{
        cout<<"APPROVED"<<endl;
    }

    
    return 0;
}