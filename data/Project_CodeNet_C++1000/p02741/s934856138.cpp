#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n==1||n==1){
        return false;
    }
    for(int i=2;i<n;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int fact(int n){
    int ans = 1;
    for(int i = 1; i<= n; ++i){
        ans *= i;
    }
    return ans;
}


int main()
{
    int nums[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int n;
    cin>>n;
    cout<<nums[n-1]<<endl;
}