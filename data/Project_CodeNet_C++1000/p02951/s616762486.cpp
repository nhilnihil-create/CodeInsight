#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    int a,b,c;cin>>a>>b>>c;
    cout<<max(0,c-(-b+a))<<endl;
}
