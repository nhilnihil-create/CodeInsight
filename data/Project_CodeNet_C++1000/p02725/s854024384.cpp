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
int r,n;
cin>>r>>n;
int maxdis=0;

int a,b,c,d;
cin>>a;
c=a;
for(int i=1;i<n;i++){
    cin>>b;
    maxdis= max(b-a, maxdis);
    a=b;
}
d= r-b;
maxdis= max(maxdis, c+d);

cout<<r-maxdis;


}