#include <iostream>
#include <vector>
#include <set>
using namespace std;
multiset<int> s;
vector<int> v;
signed main(){
    int n, x;
    cin >> n;
    int N = 1<<n;
    for(int i = 0; i < N; i++)
        cin >> x, s.insert(x);
    v.push_back(*prev(s.end()));s.erase(*prev(s.end()));
    for(int i = 1; i < N; i<<=1){
        for(int j = 0; j < i; j++){
            auto it = s.lower_bound(v[j]);
            if(it == s.begin())return cout << "No\n", 0;
            v.push_back(*(--it));
            s.erase(it);
        }
    }
    cout << "Yes\n";
}
