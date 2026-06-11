#include <bits/stdc++.h>
using namespace std;
int main(){
    long long h,c=0;
    cin>>h;
    while(h!=0){
        h/=2;
        c++;
    }
    long long ans=pow(2,c)-1;
    cout<<ans<<endl;
    return 0;
}
