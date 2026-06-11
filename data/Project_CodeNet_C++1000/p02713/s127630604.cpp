#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                sum+=gcd(gcd(i,j),k);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}