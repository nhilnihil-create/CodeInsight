// AGC 39 A 途中
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    int k; cin >> k;
    ll c = 1, head = -1, tail = 0;
    ll ans = 0;
    ll len = s.length();
    for(int i = 1; i < len; i++){
        if(s[i-1] == s[i]){
            c++;
        }else{
            ans += c/2;
            if(head == -1) head = c;
            c = 1;
        }
    }
    ans += c/2;
    tail = c;
    ans *= k;
    if(head == -1){
        cout << len*k/2 << endl; return 0;
    }else if(s[0] == s[len-1]){
        ans -= (head/2 + tail/2 - (head+tail)/2)*(k-1);
    }
    
    cout << ans << endl;
    return 0;
}