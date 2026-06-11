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
    int n,c=0;
    cin >> n;
    vector<int> p(n);
    rep0(i,n){
        cin >> p[i];
        if(p[i]!=i+1) c++;
    }
    if(c>2) coNO
    else coYES
    return 0;
}