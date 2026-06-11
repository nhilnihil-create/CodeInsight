#include <iostream>
#include <vector>

using namespace std;

class XorBase {
public:
    explicit XorBase(){}
    long long reduce(long long t) const {
        for(auto& b : base) t = min(t, t^b);
        return t;
    }
    bool add(long long t){
        t = reduce(t);
        if(!t) return false;
        base.push_back(t);
        for(int i=base.size()-2;i>=0;i--) if(base[i] < base[i+1]) swap(base[i], base[i+1]);
        return true;
    }
    long long getMax() const {
        long long res = 0;
        for(auto& b : base) res = max(res, res^b);
        return res;
    }
    bool represent(long long t) const { return reduce(t) == 0; }
private:
    vector<long long> base;
};

int main(){
    int N; cin >> N;
    long long all = 0;
    XorBase xb;
    vector<long long> a(N);
    for(auto& t : a){
        cin >> t;
        all ^= t;
    }
    for(auto& t : a) xb.add(t&~all);
    cout << 2*xb.getMax()+all << endl;
}