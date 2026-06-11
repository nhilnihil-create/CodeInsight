#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int i = 1,sum=0;
    while(i<=n){
        int num;cin>>num;
        if(num%2!=0 && i%2!=0)
            sum++;
        i++;
    }
    cout<<sum;
    return 0;
}
