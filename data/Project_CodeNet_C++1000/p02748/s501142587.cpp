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
    int A,B,m,MIN,MINA=100001,MINB=100001;
    cin >> A >> B >> m;
    vector<int> a(A),b(B);
    rep0(i,A){
        cin >> a[i];
        MINA=min(a[i],MINA);
    }
    rep0(i,B){
        cin >> b[i];
        MINB=min(b[i],MINB);    
    }
    MIN=MINA+MINB;
    vector<int> x(m),y(m),c(m);
    rep0(i,m)
        cin >> x[i] >> y[i] >> c[i];
    rep0(i,m){
        MIN=min(a[x[i]-1]+b[y[i]-1]-c[i],MIN);
        //cout << "MIN: " <<MIN << endl;
    }
    cout << MIN << endl;
    return 0;
}