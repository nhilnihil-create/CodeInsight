#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    int n;
    ll sum0=0,sum1=0,sum2=0,temp=0;
    cin >> n;
    vector<int> x(n);
    rep0(i,n){ 
        cin >> x[i];
        temp+=x[i];
    }
    temp=temp/x.size();
    rep0(i,n){
        sum0+=(x[i]-temp-1)*(x[i]-temp-1);
    }
    rep0(i,n){
        sum1+=(x[i]-temp)*(x[i]-temp);
    }
    rep0(i,n){
        sum2+=(x[i]-temp+1)*(x[i]-temp+1);
    }
    cout << min(min(sum0,sum1),sum2) << endl;
    return 0;
}