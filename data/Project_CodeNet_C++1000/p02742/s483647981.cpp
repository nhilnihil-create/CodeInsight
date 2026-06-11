#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count;
    string S;
    bool flag;
    count=0;
    ans=0;
    flag=false;
    cin >> H>>W;

    if (H==1 || W==1){
        ans=1;
    }

    else if (H%2==1 && W%2 ==1){
        ans=H*W/2+1;
    }
    else{
        ans=H*W/2;
    }
    
    cout << ans<<endl;

    return 0;
    
}
