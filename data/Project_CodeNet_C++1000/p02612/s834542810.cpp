#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
int gcd(int a,int b){
    if(b==0)
     return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    if(t%1000==0)
     cout<<0<<endl;
    else
     cout<<1000-t%1000;
}
