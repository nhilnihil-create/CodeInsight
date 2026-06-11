#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n,l,sum=0;
    int kouho = 100000;
    cin >> n >> l;
    rep(i,n){
        sum += i+l;
        kouho = min(kouho,abs(l+i));
    }
    if(sum>0) cout << sum-kouho<<endl;
    else cout << sum+kouho << endl;
    
}