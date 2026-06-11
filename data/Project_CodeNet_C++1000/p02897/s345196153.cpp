#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;

using namespace std;

int main(){
    
    int N;
    cin>>N;
    if(N%2==0){
        cout<<std::fixed<<std::setprecision(10)<<0.5<<endl;
        
    }
    else{
        cout<<std::fixed<<std::setprecision(10)<<(double)(N/2+1)/N<<endl;
        
    }
}