#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define coYes cout << "Yes" << endl
#define coYES cout << "YES" << endl
#define coyes cout << "yes" << endl
#define coNo cout << "No" << endl
#define coNO cout << "NO" << endl
#define cono cout << "no" << endl
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){ //最大公約数
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    ll n,temp;
    ll sum=0;
    cin >> n;
    vector<ll> a(n+1),b(n);
    rep0(i,n+1)
        cin >> a[i];
    rep0(i,n)
        cin >> b[i];
    rep0(i,n){

        if(a[i]<b[i]){
            sum+=a[i];
            b[i]-=a[i];
            temp=min(a[i+1],b[i]);
            sum+=temp;
            a[i+1]-=temp;
        }else sum+=b[i];
    }
    cout << sum << endl;
    return 0;
}