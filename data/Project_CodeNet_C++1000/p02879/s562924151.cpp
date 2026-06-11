#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int a,b;
    cin>>a>>b;
    if(a>=10||b>=10){
        cout << -1 <<endl;
        return 0;
    }
    cout<<a*b<<endl;
}