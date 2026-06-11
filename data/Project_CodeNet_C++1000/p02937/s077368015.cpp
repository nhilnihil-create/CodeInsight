#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;
const ll MOD=1e9+7;

int main() {
    string s,t;
    cin>>s>>t;
    vvi pl(26,vi(0));
    for (int i=0;i<int(s.size());i++){
        int num=s[i]-'a';
        pl[num].push_back(i);
    }
    ll ans=0;
    ll now=0;
    ll c=0;
    int b=1;
    for (int i=0;i<int(t.size());i++){
        int num=t[i]-'a';
        if (pl[num].size()==0){
            b=0;
            break;
        }
        else{
            int num1=pl[num].size();
            if (pl[num][num1-1]<now){
                now=pl[num][0]+1;
                c+=1;
            }
            else{
                auto index=lower_bound(all(pl[num]),now)-pl[num].begin();
                now=pl[num][index]+1;
            }
        }
    }
    ll ss=ll(s.size());
    if (b==0){
        cout<<-1<<endl;
    }
    else{
        unsigned long long c1=c;
        unsigned long long sss=ss;
        unsigned long long now1=now;
        cout<<c1*sss+now1<<endl;
    }

    return 0;
}
