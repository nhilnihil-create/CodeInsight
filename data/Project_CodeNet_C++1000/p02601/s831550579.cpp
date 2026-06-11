#include<iostream>
using namespace std;

int main(){
    int A,B,C,K;
    cin>>A>>B>>C;
    cin>>K;
    int n=0;
    while(B<=A){
        B=B*2;
        n++;
        if(n>K){
            cout<<"No"<<endl;
            return 0;
        }
    }
    while(C<=B){
        C=C*2;
        n++;
        if(n>K){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}