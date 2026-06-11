#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

long beki(int n){
    if(n==0) return 1L;
    else return beki(n-1)*10;
}

int main() {
    int n;
    cin>>n;
    string nn=std::to_string(n);
    long ans=0;
    if(nn.length()%2==0){
        for(int i=0;i<nn.length()-1;i+=2){
            ans=ans+beki(nn.length()-i-1)-beki(nn.length()-i-2);
        }
    }else{
        ans=n-beki(nn.length()-1)+1;
        for(int i=1;i<nn.length();i+=2){
            ans=ans+beki(nn.length()-i-1)-beki(nn.length()-i-2);
        }
    }
    cout<<ans<<endl;
}