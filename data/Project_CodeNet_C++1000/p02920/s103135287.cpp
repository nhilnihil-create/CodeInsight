#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
using namespace std;
using ll = long long int;
using P = pair<int, int>;

int main(){
    ll n;
    cin >> n;
    ll Snum = (1LL << n);
    vector<ll> S(Snum);
    for(int i = 0; i < Snum; i++)cin >> S[i];

    sort(S.begin(), S.end());
    vector<int> parent;
    parent.push_back(S[Snum-1]);
    multiset<int> child;
    for(int i = 0; i < Snum-1; i++)child.insert(S[i]);
    bool ans = true;
    for(int i = 1; i <= n; i++){
        int num = parent.size();
        for(int j = 0; j < num; j++){
            multiset<int>::iterator it = child.lower_bound(parent[j]);
            if (it == child.begin()){
                cout << "No" << endl;
                return 0;
            }
            --it;
            parent.push_back(*it);
            child.erase(it);
        }
    }
    cout << "Yes" << endl;
    return 0;
}   