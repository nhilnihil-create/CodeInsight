#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n;
    cin>>n;
    long long int sum=0;
    if (n%2==0) {
        for (long long int i=10;i<=n;i*=5) {
            sum+=n/i;
        }
        cout<<sum<<endl;
    } else {
        cout<<0<<endl;
    }
}