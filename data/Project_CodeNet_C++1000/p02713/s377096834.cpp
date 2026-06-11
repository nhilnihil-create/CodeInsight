#include<bits/stdc++.h>

using namespace std;
int main(){
    long n;
    cin >> n;
    long sum=0;
    int ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
               ans=__gcd(i,j);
               sum+=__gcd(ans,k);
            }
        }
    }
    cout << sum << endl;
   return 0;
}