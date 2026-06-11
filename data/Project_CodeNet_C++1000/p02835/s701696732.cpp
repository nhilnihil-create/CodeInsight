#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000000000
#define MOD 1000000007

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    if(a1+a2+a3>=22){
        cout<<"bust"<<endl;
    }else{
        cout<<"win"<<endl;
    }
    return 0;
}