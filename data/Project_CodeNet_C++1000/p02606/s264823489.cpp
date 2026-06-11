#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,d;
    cin>>l>>r>>d;
    if(l>r) cout<<0<<endl;
    else
    cout<<(r/d)-((l-1)/d)<<endl;
}
