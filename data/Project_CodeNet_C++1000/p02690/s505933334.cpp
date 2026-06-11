#include<iostream>
using namespace std;

int main(){
    long long x;
    cin>>x;

    for(long long i=-200;i<200;++i){
        for(long long j=-200;j<200;++j){
            long long a=i*i*i*i*i;
            long long b=j*j*j*j*j;
            if(a-b==x){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
        }
    }
}