#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long a,b,q=1;
    cin>>a>>b;
    for(int i=2;i<100000;i++){
        if(a%i==0&&b%i==0){
            q=i;
        }
    }
    cout<<(a*b)/q<<endl;
    
}
