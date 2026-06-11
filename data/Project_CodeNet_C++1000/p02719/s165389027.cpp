#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;
    cin>>n>>k;
    n%=k;
    long long int s;
    s=abs(n-k);
    if(s>=n) cout<<n<<endl;
    else cout<<s<<endl;
    


}