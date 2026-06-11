#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll X; cin>>X;

    ll A=1000*(X/500);
    ll B=5*((X%500)/5);
    cout<<A+B<<endl;
}
