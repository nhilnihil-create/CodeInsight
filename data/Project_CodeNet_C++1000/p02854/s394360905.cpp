#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    
    bool flag;
    count=0;
    ans=std::pow(10,18);
    flag=false;
    cin >>N;
    Ssum[0]=0;
    for (i=0;i<N;i++){
        cin >> S[i];
        Ssum[i+1]=Ssum[i]+S[i];
    }
    for (i=1;i<N;i++){
        
        tmp=abs(Ssum[i]-(Ssum[N]-Ssum[i]));
        if (ans>tmp){
            ans=tmp;
        }
        
    }
    

    
    cout << ans<<endl;

    return 0;
    
}
