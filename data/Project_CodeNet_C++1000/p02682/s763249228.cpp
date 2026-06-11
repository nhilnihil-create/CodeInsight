#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int a, b, c, k;
cin>>a>>b>>c>>k;
if(k <= a){
    cout<<k;
    return 0;
}else
{
    k -= a;
    if(k <= b){
        cout<<a;
        return 0;
    }else
    {
        k -= b;
        cout<<a-k;
        return 0;
    }
    
}
return 0;    
}