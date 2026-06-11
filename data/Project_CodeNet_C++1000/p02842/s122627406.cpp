#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define coYes cout << "Yes" << endl;
#define coYES cout << "YES" << endl;
#define coyes cout << "yes" << endl;
#define coNo cout << "No" << endl;
#define coNO cout << "NO" << endl;
#define cono cout << "no" << endl;
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    ll n;
    cin >> n;
    for(int i=n;i>0;i--){
        int temp=i*1.08;
        //cout << temp << endl;
        if(n==temp){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}