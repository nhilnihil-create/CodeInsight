#include <iostream>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<m;++i){
        int a;
        cin>>a;
        sum+=a;
    }
    cout<<(n>=sum?n-sum:-1)<<endl;
}
