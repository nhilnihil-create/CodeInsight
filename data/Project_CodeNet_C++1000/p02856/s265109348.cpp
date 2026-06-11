//double太大了精度会丢
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>

typedef long long ll;

const int MAX_M = 200000 + 7;

using namespace std;
ll c[MAX_M];
ll d[MAX_M];

int main(){
    ios::sync_with_stdio(0);

    /*
    int n;
    cin>>n;
    ll Sum = 0,num = 0;
    for(int i = 1;i <= n;++i){
        ll a,b;
        cin>>a>>b;
        Sum += a*b;
        num += b;

    }
    num = num - 1 + (Sum - 1) /9;
    cout<<num<<endl;
    */

    int m;
    cin >> m;
    ll digit_sum=0;
    ll byte = 0;
    for (int i = 1; i <= m; i++){
        ll a, b;
        cin >> a >> b;
        digit_sum += a*b;
        byte += b;
    }
    
    ll k1 = digit_sum / 9;   
    if(digit_sum % 9 == 0){
        k1--;
    }
    ll k2 = byte - 1;    
    cout << (k1+k2) << endl;
    return 0;
}