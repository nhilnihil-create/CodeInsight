#include<bits/stdc++.h>
using namespace std;




int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    long long int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long int f=n/i;
        sum+=i*(f*(f+1))/2;
    }
    cout<<sum;
  
  
}
  
    




