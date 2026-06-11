#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;


int main() {

double n;
cin>>n;
int ans;
ans=n/1.08;
int sum1=ans*1.08,sum2=(ans+1)*1.08,sum3=(ans-1)*1.08;

if(n==sum1){
    cout<<ans<<endl;
}
else if(n==sum2){
    cout<<ans+1<<endl;
}
else if(n==sum3){
    cout<<ans-1<<endl;
}
else{
    cout<<":("<<endl;
}
}