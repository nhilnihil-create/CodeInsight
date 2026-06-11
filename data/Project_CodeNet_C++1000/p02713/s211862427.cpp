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
int K;
cin>>K;

ll ans=0;
//cout<<gcd(2,5);
for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
        for(int k=1;k<=K;k++){
                ans+=gcd(gcd(i,j),k);   
        }
    }
}
cout<<ans;

}