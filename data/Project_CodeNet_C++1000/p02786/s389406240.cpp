#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;

ll pow(ll a,ll b){
    if(b==0){
        return 1;
    }else{
        if(b%2==0){
            return pow(a*a,b/2);
        }else{
            return pow(a*a,b/2)*a;
        }
    }
}

int main(){
    ll H;
    cin>>H;
    
    int cnt=0;
    while(H>1){
        H/=2;
        cnt++;
    }

    cout<<pow(2,cnt+1)-1<<endl;

    return 0;
}