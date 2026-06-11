#include <iostream>
using namespace std;

int main() {
    long long int n,sum;

    cin>>n;
    sum=n-1;
    for(long long int i=1;i*i<=n;i++){
        if(n%i==0){
            long long int minsum=i+n/i-2;
            if(sum>minsum)
                sum=minsum;
        }
    }
    cout<<sum;



    return 0;
}