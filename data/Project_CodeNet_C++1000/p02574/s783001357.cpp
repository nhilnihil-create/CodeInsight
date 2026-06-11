#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

vector<int> factor(int n){
    vector<int> res;

    for (int i = 2; i*i <= n; ++i) {
        while(n % i == 0){
            res.push_back(i);
            n /= i;
        }
    }
    if(n != 1) res.push_back(n);

    return res;
}

int main(void){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int not_coprime = a[0];
    for(int i = 1; i < n; ++i){
        not_coprime = gcd(not_coprime, a[i]);
    }
    if(not_coprime != 1){
        cout << "not coprime" << "\n";
        return 0;
    }

    set<int> pr;
    for(int i = 0; i < n; ++i){
        vector<int> x = factor(a[i]);
        set<int> ps(all(x));

        for(auto v : ps){
            if(pr.find(v) != pr.end()){
                cout << "setwise coprime" << "\n";
                return 0;
            }
            pr.insert(v);
        }
    }
    cout << "pairwise coprime" << "\n";

    return 0;
}
