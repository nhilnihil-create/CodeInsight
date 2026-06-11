#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A,B,C,K;
    cin>>A>>B>>C>>K;
    
    int t=0;
    for(;t<=K&&B<=A;++t){
        B<<=1;
    }
    for(;t<=K&&C<=B;++t){
        C<<=1;
    }
    cout<<((t<=K)?"Yes":"No")<<endl;
    
    return 0;
}