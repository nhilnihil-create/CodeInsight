#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(0);	//解决c++输入输出流被卡问题
    ll n,m,sum;
    cin >> n >> m >> sum;
    _for(i,0,m){
        cout << sum << " ";
    }
    _for(i,0,n-m){
        if(sum != 1000000000){
            cout << sum + 1 << " ";
        }
        else
        {
            cout << sum - 1 << " ";
        }
        
    }
    cout << endl;
    
    return 0;
}