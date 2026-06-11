#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string N;cin>>N;
    int count=0;
    for(int i=0;i<N.size();i++){
        count+=N[i]-'0';
    }
    if(count%9==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
