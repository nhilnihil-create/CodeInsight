#include <bits/stdc++.h>
using namespace std;

template<class T, class Func = function<T(T,T)>>
class CumulativeSum{
public:
    vector<T>sum;
    T e;
    CumulativeSum(const vector<T>v,T e,const Func& f = [](T a, T b){return a + b;}) : sum(v.size()),e(e){
        copy(v.begin(),v.end(),sum.begin());
        T past = 0;
        for(auto & itr : sum){
            itr = f(itr,past);
            past = itr;
        }
    }
    //[l,r)
    auto query(int l, int r, const Func& f = [](T a,T b){return a - b;}){
        if(r > 0) return f(sum[r - 1],(l == 0 ? e : sum[l - 1]));
        else return e;
        
    }
    auto begin(){
        return sum.begin();
    }
    auto end(){
        return sum.end();
    }
    auto& operator[] (int idx){
        return sum[idx];
    }
};
int main(){
    long long N,M,K;
    cin >> N >> M >> K;
    vector<long long>a(N),b(M);
    for(auto& e : a) cin >> e;
    for(auto& e : b) cin >> e;
    auto asum = CumulativeSum<long long>(a,0LL);
    auto bsum = CumulativeSum<long long>(b,0LL);
    long long ans = 0;
    for(long long i = 0; i <= N; ++i){
        long long tmp  = asum.query(0,i);
        if(tmp > K) continue;
        ans = max(ans,i);
        long long dif = K - tmp;
        auto itr = upper_bound(bsum.sum.begin(), bsum.sum.end(),dif);
        if(itr == bsum.sum.begin()) continue;
        itr = prev(itr);
        ans = max(ans, i + distance(bsum.sum.begin(),itr) + 1);
    }
    cout << ans << endl;
}
