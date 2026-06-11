#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    string S,T,U;
    cin>>S>>T;
    int A,B;
    cin>>A>>B;
    cin>>U;
    if(S==U){
        A--;
    }else{
        B--;
    }
    cout<<A<<" "<<B<<endl;

    return 0;
}