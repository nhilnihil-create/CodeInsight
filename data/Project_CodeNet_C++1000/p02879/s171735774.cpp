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
    
        if (N<10 && H<10){
            cout <<N*H <<endl;
        }else{
            cout <<-1 <<endl;
        }
    

    
    

    return 0;
    
}
