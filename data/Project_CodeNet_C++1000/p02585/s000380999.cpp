#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int n, k; cin >> n >> k;
    int p[n], c[n];
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i,n) cin >> c[i];
    vector<vector<int> > v;
    vector<bool> b(n,false);
    rep(i,n) {
        if (b[i]) continue;
        v.push_back({c[i]});
        b[i] = true;
        int j = p[i];
        while (j != i) {
            v.back().push_back(c[j]);
            b[j] = true;
            j = p[j];
        }
    }
    int l, q, r;
    long long int sum, d[10010], ans = -1e14;
    for (auto s : v) {
        l = s.size();
        q = k/l; r = k%l;
        sum = 0;
        for (int i = 0; i < l; i++)
        {
            sum += s[i];
        }
        
        d[0] = s[0]; d[l] = sum+s[0];
        for (int i = 0; i < l-1; i++)
        {
            d[i+1] = d[i] + s[i+1];
            d[l+i+1] = d[i+1] + sum;
        }
        /*
        for (int i = 0; i < 2*l; i++) cout << d[i] << " ";
        cout << endl;
        cout << "l:" << l << endl;
        */
        if (q == 0)
        {
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    ans = max(ans,d[i+j+1]-d[i]);
                    //cout << d[i+j+1]-d[i] << endl;
                }
            }
        }
        else {
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    ans = max(ans,max(d[i+j+1]-d[i],d[i+j+1]-d[i]+sum*q));
                    //cout << d[i+j+1]-d[i] << endl;
                }
            }
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    ans = max(ans,max(d[i+j+1]-d[i],d[i+j+1]-d[i]+sum*(q-1)));
                    //cout << d[i+j+1]-d[i] << endl;
                }
            }

        }
        
        
        //cout << ans << endl;
    }
    cout << ans << endl;




    /*
    cout << v.size() << endl;
    for (auto s : v) {
        for (auto x : s) {
            cout << x << " ";
        }
        cout << endl << s.size() << endl;
    }
    */
    return 0;
}
