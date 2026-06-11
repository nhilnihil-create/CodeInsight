#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    ll n;
    cin >> n;
    ll k=0;
    int m=0;
    while(k<n){
        m++;
        k+=pow(26,m);
    }
    ll a,ans,b;
    char x;
    for(int i=1;i<=m;i++){
        a=pow(26,m-i);
        b=n-(k-pow(26,m));
        ans=(b-1)/a;
        x=char(ans+'a');
        cout << x;
        n-=a*ans;
    }
    cout << endl;

} 
    