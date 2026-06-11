#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    int a,b;cin>>a>>b;
    if((a+b)%2==1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<(a+b)/2<<endl;
    }
}