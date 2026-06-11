#include <bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define scd(x) scanf("%d",&x)
#define scdd(x,y) scanf("%d%d",&x,&y)
const int maxn=3e5+10;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
multiset<int>s;
vector<int>vec;
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    int n;
    //cout<<(1<<18)<<endl;
    scd(n);
    int la=1<<n;
    int mx=0;
    for(int i=1; i<=la; i++) {
        int x;
        scd(x);
        s.insert(x);
        mx=max(x,mx);
    }
    bool flag=false;
    vec.clear();
    vec.push_back(mx);
    multiset<int>::iterator it=s.lower_bound(mx);
    s.erase(it);
    while(!flag) {
        if(vec.size()==la) {
            flag=true;
            break;
        }
        int siz=vec.size();
        for(int i=0; i<siz; i++) {
            multiset<int>::iterator it = s.lower_bound(vec[i]);
            if(it==s.begin()){
                flag=true;break;
            }
            it--;
            vec.push_back(*it);
            s.erase(it);
        }
    }
    if(vec.size()==la)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
