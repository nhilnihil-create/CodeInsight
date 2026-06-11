#include <bits/stdc++.h>
using namespace std;

struct BIT{
    vector<int> data;

    void init(int n){
        data.assign(n+1, 0);// 1-indexed [1,n]
    }

    void add(int i, int x){
        while(i <= data.size()){
            data[i] += x;
            i += (i & -i);
        }
    }

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += data[i];
            i -= (i & -i);
        }
        return s;
    }
};

int main(){
    int n;
    long long int d, a;
    cin >> n >> d >> a;

    vector<pair<long long int, long long int>> monster(n);
    vector<long long int> x(n);
    for(int i=0; i<n; i++){
        cin >> monster[i].first >> monster[i].second;
        x[i] = monster[i].first;
    }
    sort(monster.begin(), monster.end());
    sort(x.begin(), x.end());

    BIT bit;
    bit.init(n+1);

    long long int ans = 0;
    for(int i=0; i<n; i++){
        long long int mx = monster[i].first;
        int ni = upper_bound(x.begin(), x.end(), mx + 2*d) - x.begin();
        //cout << monster[i].second << " " << bit.sum(i+1) * a << endl;

        int times = max(0LL, (monster[i].second - bit.sum(i+1) * a + a - 1) / a);
        
        bit.add(i+1,   times);// 1-indexed
        bit.add(ni+1, -times);// 1-indexed
        ans += times;
    }
    cout << ans << endl;
    return 0;
}