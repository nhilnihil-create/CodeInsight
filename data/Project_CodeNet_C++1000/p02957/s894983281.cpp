#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll A,B;
    cin>>A>>B;
    ll dk=abs(A-B);
    if(dk%2!=0)cout<<"IMPOSSIBLE"<<endl;
    else cout<<min(A,B)+(dk/2)<<endl;
}