#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n;
    string s="",t="", m="";
    for(int i=0; i<n; i++){
        cin >> x;
        s+=(char)(x+'0');
    }
    for(int i=0; i<n; i++){
        cin >> x;
        t+=(char)(x+'0');
    }
    for(int i=1; i<=n; i++){
        m+=(char)(i+'0');
    }
    int cnt = 0, ans1 ,ans2;
    while(1){
        cnt++;
        if(m==s) ans1 = cnt;
        if(m==t) ans2 = cnt;
        if(!next_permutation(m.begin(), m.end())) break;
    }
    cout << abs(ans1- ans2);
return 0;
}
