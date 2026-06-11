#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int decode(string s){
    string str = "ixcm";
    int digit[] = {1,10,100,1000};
    int res = 0;
    rep(j,0,4){
        rep(i, 0, s.size()){
            if(s[i] == str[j]){
                int t = 1 * digit[j];
                if(i && s[i-1] >= '2' && s[i-1] <= '9'){
                    t *= s[i-1] - '0';
                }
                res += t;
            }
        }
    }
    return res;
}
string encode(int n){
    string res;
    string str = "mcxi";
    string ss = to_string(n);
    ss = string(4 - ss.size(), '0') + ss;
    //cout << ss << endl;
    rep(i,0,ss.size()){
        string sub;
        if(ss[i] == '0')continue;
        if(ss[i] != '1')sub.push_back(ss[i]);
        sub.push_back(str[i]);
        res += sub;
    }
    return res;
}
main(){
    int N;
    cin >> N;
    rep(i,0,N){
        string s,t;
        cin >> s >> t;
        int a = decode(s), b = decode(t);
        //cout << a << " " << b << endl;
        cout << encode(a + b) << endl;
    }
}
