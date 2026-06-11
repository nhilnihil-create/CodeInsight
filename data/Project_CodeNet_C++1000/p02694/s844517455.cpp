#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long m = 100;
    int ans = 0;
    for(int i=0;i<10000;i++){
        if(m>=n)break;
        m+=m/100;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
