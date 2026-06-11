#include<iostream>
#define M 1000000000LL
using namespace std;
long long S;
int main(){
    cin>>S;
    cout<<0<<" "<<0<<" "<<M<<" "<<M-(S%M?S%M:M)<<" "<<1<<" "<<(S+M-1)/M<<endl;
    return 0;
}