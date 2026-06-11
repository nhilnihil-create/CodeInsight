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
string str;
cin>>str;

if(str[2]==str[3] && str[4]==str[5])
    cout<<"Yes";
else
    cout<<"No";

}