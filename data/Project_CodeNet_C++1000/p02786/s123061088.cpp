#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int H){
    if(H==1) return 1;
    else return 1+2*solve(H/2);
}
int main(){
    long long int H; cin>>H;
    cout<<solve(H)<<endl;
}