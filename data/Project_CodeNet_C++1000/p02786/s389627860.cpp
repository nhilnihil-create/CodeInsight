#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll H;
    cin>>H;
    
    ll l = log(H)/log(2)+1;


    cout<<ll(pow(2, l))-1<<endl;   
    return 0;
}
