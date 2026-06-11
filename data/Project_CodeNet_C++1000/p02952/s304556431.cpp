#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a=0,ans=0;
    cin>>n;

    for(int i=1; i<=n; i++){
        a=(int)log10((double)i)+1;
        if(a%2==1) ans++;
    }
    cout<<ans<<endl;
}
