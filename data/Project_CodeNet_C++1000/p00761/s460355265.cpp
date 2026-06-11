#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
string to_str(ll A){
    stringstream ss;
    ss << A;
    return ss.str();
}
main(){
    int A,L;
    cin >> A >> L;
    while(L){
        int cnt = 0;
        int next = A;
        map<int,int> mp;
        do{
            mp[next] = cnt;
            string hi,lo;
            lo = hi = to_str(next);
            sort(lo.begin(), lo.end());
            sort(hi.rbegin(), hi.rend());
            if(hi.length() < L)hi += string(L - hi.length(),'0');
            //cout << hi << " " << lo << endl;
            next = stoi(hi) - stoi(lo);
            cnt++;
            //cout << next << endl;
        }while(mp.find(next) == mp.end());
        cout << mp[next] << " " << next << " " << cnt - mp[next] << endl;
        cin >> A >> L;
    }
}
