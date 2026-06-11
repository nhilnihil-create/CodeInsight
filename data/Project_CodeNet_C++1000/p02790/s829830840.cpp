#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    string T;
    bool flag;
    count=0;
    ans=std::pow(10,18);
    flag=false;
    cin >>N>>H;
    
        if (N>H){
            for (i=0;i<N;i++){
                cout <<H;
            }
            cout <<endl;
        }
        else{
            for (i=0;i<H;i++){
                cout <<N;
            }
            cout <<endl;
        }
    

    
    

    return 0;
    
}
