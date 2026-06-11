#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    ull n;
    cin>>n;
    ull steps=0;
    ull amt=100;
    while(amt<n){
        steps++;
        amt+=amt/100;
    }
    cout<<steps<<endl;
}
