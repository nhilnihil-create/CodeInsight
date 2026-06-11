#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp=i*1.08;
        if(tmp==n){
            cout<<i<<endl;
            break;
        }else if(tmp>n) {
            cout<<":("<<endl;
            break;
        }
    }
    return 0;
}