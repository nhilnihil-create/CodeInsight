#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

vector<int> m;
vector< pair<int,int> > q;

void fact(int x){
    for(int i = 2; i * i <= x; i++){
        if (x % i == 0) {
            pair<int, int> p;
            p.first = i;
            p.second = 0;
            while(x % i == 0){
                x /= i;
                p.second++;
            }
            q.push_back(p);
        }
    }
    if (x != 1) {
        pair<int, int> p;
        p.first = x;
        p.second = 1;
        q.push_back(p);
    }
}

void fact2(int c[], int num){
    if (num == q.size()) {
        // for(int i = 0; i < q.size(); i++){
        //     cout << q[i].first << " " << c[i] << endl;
        // }
        
        int fac = 1;
        for(int i = 0; i < q.size(); i++){
            fac *= pow(q[i].first, c[i]);
        }
        
        m.push_back(fac);
        return;
    }
    int d[q.size()];
    for(int i = 0; i < q.size(); i++){
        d[i] = c[i];
    }
    for(int i = 0; i <= q[num].second; i++){
        d[num] = i;
        fact2(d, num + 1);
    }
    
}


int main(){

    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];

    int sm = 0;
    rep(i, n) sm += a[i];

    fact(sm);
    int b[q.size()];
    fact2(b, 0);
    // for(int i = 0; i < q.size(); i++){
    //     cout << q[i].first << " " << q[i].second << endl;
    // }
    // for(int i = 0; i < m.size(); i++){
    //     cout << m[i] << endl;
    // }
    sort(m.begin(), m.end(), greater<int>());
    for(int i = 0; i < m.size(); i++){
        int mod = m[i];
        int md[n];
        for(int j = 0; j < n; j++){
            md[j] = a[j] % mod;
        }
        sort(md, md + n);
        int ans = 0;
        int modsm = 0;
        for(int j = 0; j < n; j++){
            modsm += md[j];
        }
        modsm /= mod;
        for(int j = n - 1; j >= n - modsm; j--){
            ans += mod - md[j];
        }
        if (ans <= k) {
            cout << mod << endl;
            return 0;
        }   
    }
    cout << 1 << endl;
}