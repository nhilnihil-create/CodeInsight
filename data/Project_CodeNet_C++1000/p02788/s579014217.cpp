#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using ll=long long;
using namespace std;

template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main(){
    int N,D,A;
    cin>>N>>D>>A;

    vector<pair<int,int>> map;
    int a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        map.push_back({a,b});
    }
    map.push_back({1000000001,0});
    sort(map.begin(),map.end());

    BIT<int> bit(N+3);
    for(int i=0;i<N;i++){
        bit.add(i+1,i+2,map[i].second);
    }

    ll ans=0;
    int ed=0;

    for(int i=0;i<N;i++){
        if(bit.sum(i+1,i+2)>0){
            int range=map[i].first+2*D;
            int numBom=(bit.sum(i+1,i+2)+A-1)/A;
            ans+=numBom;
            int damage=numBom*A;
            while(ed<N && map[ed].first<=range){
                ed++;
            }
            bit.add(i+1,ed+1,-damage);
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}