#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    long long int N,M,H,W,x,i,j,k,ans,count,cost,tmp,a,b,c,d,c1,c2,HP;
    long long int S[110000];
    //long long int T[11000];
    //long long int U[300000];
    //long long int Ssum[300000];
    string T[110],TA,V,G,ans2;
    bool flag;
    count=0;
    ans=std::pow(10,18);
    ans=0;
    flag=false;
    cin >>N;
    for (i=0;i<N;i++){
        cin>>S[i];
        
    }
    

    
        //cin >> c >>d;
        //count=0;
    
    //cout << count<<endl;
    for (i=0;i<N-1;i++){
        for (k=i+1;k<N;k++){
            ans+=S[i]*S[k];
        }
    }
    
    
    
        cout << ans << endl;
    

    return 0;
    
}
