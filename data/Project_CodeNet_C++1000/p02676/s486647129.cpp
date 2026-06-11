#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){

    int K;
    string S;
    cin>>K>>S;

    if(S.size()<=K){
        cout<<S<<endl;
    }else{
        cout<<S.erase(K)<<"..."<<endl;
    }
    
    return 0;
}