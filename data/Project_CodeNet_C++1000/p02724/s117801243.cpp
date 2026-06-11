#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long

int gcd(int a, int b){
    
    if(b==0)
    return a;
    
    return gcd(b, a%b);
    
}
int main(){
int N;
cin>>N;

ll ans=0;
if(N==0)
    cout<<0;
else{
    ans+= (N/500)*1000;
    int rem= N%500;
    if(rem!=0)
        ans+=(rem/5)*5;
        cout<<ans;
}

}