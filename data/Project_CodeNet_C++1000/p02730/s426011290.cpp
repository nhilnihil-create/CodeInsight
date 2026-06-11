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
    string s;
    bool flag=true;
    cin >> s;
    rep0(i,s.length()/2){
        if(s[i]!=s[s.length()-i-1])  flag=false;
    }
    rep0(i,(s.length()-2)/2){
        if(s[i]!=s[(s.length()-1)/2-i-1]) flag=false;           
    }
    for(int i=(s.length()+3)/3-1;2*i<s.length()-1;i++){
        if(s[i]!=s[s.length()-i-1]) flag=false;           
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}