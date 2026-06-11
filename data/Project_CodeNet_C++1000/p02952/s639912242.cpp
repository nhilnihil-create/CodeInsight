#include <iostream>
#include <cmath>

using namespace std;
int popcount(int num){
    if(num == 0) return 0;
    if(num % 2 == 1) return 1 + popcount(num/2);
    if(num % 2 == 0) return popcount(num/2);
}

int digit10(int num){
    if(num == 0) return 0;
    return 1 + digit10(num/10);
}

int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(digit10(i+1) % 2 == 1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}