#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long n,a,b;
    cin >> n >> a >> b;

    long long ans =0;
    if((b-a)%2==1){
        long long num1 = a+(b-a-1)/2;
        long long num2 = n-b+1+(b-a-1)/2;
        ans = min(num1,num2);
    }else{
        ans =(b-a)/2;
    }

    cout << ans << endl;
}

