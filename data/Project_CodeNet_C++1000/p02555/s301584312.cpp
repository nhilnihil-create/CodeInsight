#include <iostream>
using namespace std;
#define MOD 1000000007

int main(int argc, const char * argv[]) {
    int S;
    cin>>S;
    
    int a=0,a_1=0,a_2=0,a_3=1;
    for(int i=2;i<S;++i){
        a=a_1+a_3;
        a%=MOD;
        a_3=a_2;
        a_2=a_1;
        a_1=a;
    }
    cout<<a<<endl;
    
    return 0;
}