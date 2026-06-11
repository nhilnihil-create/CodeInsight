#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    if(n<k){
        long long ans = n%k;
        long long ans1 = k-ans;
        n = min(ans,ans1);
    }
    else{
        long long ans = n%k;
        while(ans>k){
            ans = ans%k;
        }
        long long ans2 = n%k;
        long long ans3 = k-ans2;
        n = min(ans2,ans3);
    }
    cout << n <<endl;
    return 0;
}
