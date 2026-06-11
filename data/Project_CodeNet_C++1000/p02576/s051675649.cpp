#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string strd(int n){
    string x;
    while(n){
        int d=n%10;
        x+=(d+'0');
        n/=10;
    }
    reverse(x.begin(),x.end());
    return x;
}
void digit()
{
    for(int i=1;i<=10000;i++){
        s+=strd(i);
    }
}
int main()
{
     int n,x,t;
     cin>>n>>x>>t;
     if(n%x==0)n/=x;
        else n=n/x+1;
     cout<<n*t<<endl;
}
