#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

struct arm{
    ll min, max;
};
bool cmp_max(const arm &x, const arm &y){
    return x.max < y.max;
}

int main(){
    int n;
    cin >> n;
    vector<arm> Arm;
    for(int i=0;i<n;i++){
        ll x, l;
        cin >> x >> l;
        arm a;
        a.min = x - l;
        a.max = x + l;
        Arm.push_back(a);
    }
    sort(Arm.begin(), Arm.end(), cmp_max);
    int ans = 1;
    ll max = Arm[0].max;
    for(int i=1;i<n;i++){
        if(max <= Arm[i].min){
            ans++;
            max = Arm[i].max;
        }
    }

    cout << ans << endl;
    return 0;
}