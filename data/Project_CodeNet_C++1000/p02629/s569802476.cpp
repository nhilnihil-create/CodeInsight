#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

char change(ll x){
    if(x==0) return 'z';
    if(x==1) return 'a';
    if(x==2) return 'b';
    if(x==3) return 'c';
    if(x==4) return 'd';
    if(x==5) return 'e';
    if(x==6) return 'f';
    if(x==7) return 'g';
    if(x==8) return 'h';
    if(x==9) return 'i';
    if(x==10) return 'j';
    if(x==11) return 'k';
    if(x==12) return 'l';
    if(x==13) return 'm';
    if(x==14) return 'n';
    if(x==15) return 'o';
    if(x==16) return 'p';
    if(x==17) return 'q';
    if(x==18) return 'r';
    if(x==19) return 's';
    if(x==20) return 't';
    if(x==21) return 'u';
    if(x==22) return 'v';
    if(x==23) return 'w';
    if(x==24) return 'x';
    if(x==25) return 'y';
    if(x==26) return 'z';
}

int main(){
    ll n;
    cin >> n;
    ll k=1;
    ll x1=1;
    ll x2=26;
    bool flag=false;
    while(1){
        if(x1<=n && n<=x2){
            flag=true;
        }
        if(flag) break;
        k++;
        x1*=26; x2=26*x1+x2;
    }
    vector<ll> a(k);
    for(int i=0;i<k;i++){
        a[i]=n%26;
        if(a[i]==0) n -= 26;
        n /= 26;
    }
    for(int i=k-1;i>=0;i--){
        char s=change(a[i]);
        cout << s;
    }
    cout << endl;
}