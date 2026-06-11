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
double l;
cin>>l;
double a=3;

cout<<fixed<<setprecision(12)<<(l/a)*(l/a)*(l/a);


}