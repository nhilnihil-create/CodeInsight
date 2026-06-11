#include<bits/stdc++.h>
using namespace std;

class Osa_k {
private:
    int n;
    vector<int> factor;
public:
    Osa_k(int _n):n(_n) {
        factor.assign(n, 0);
        iota(factor.begin(), factor.end(), 0);
        for(int i = 2; i < n; i++) {
            if(factor[i] != i)continue;
            for(int j = i + i; j < n; j += i) factor[j] = i;
        }
    }

    vector<pair<int,int>> fact(int v) {
        map<int, int> ret;
        while(v != factor[v]) {
            ret[factor[v]]++;
            v /= factor[v];
        }
        if(v != 1)ret[v]++;
		vector<pair<int,int>> t;
		for(auto i : ret)t.push_back(i);
        return t;
    }

    vector<int> divisor(int v) {
        vector<int> que = {1};
        vector<pair<int,int>> a = fact(v);
        for(auto i : a) {
            int num = 1;
            vector<int> nxt;
            for(int j = 0; j <= i.second; j++) {
                int m = que.size();
                for(int k = 0; k < m; k++)nxt.push_back(num * que[k]);
                num *= i.first;
            }
            swap(que, nxt);
        }
        sort(que.begin(), que.end());
        return que;
    }

}fact(1000001);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> in(1000001);
    for(int i = 0; i < n; i++)cin >> a[i], in[a[i]]++;
    int sum = 0;
 
    for(int i = 0; i < n; i++) {
        vector<int> num = fact.divisor(a[i]);
        int res = 0;
        for(int j = 0; j < (int)num.size(); j++) {
            res += in[num[j]];
        }
        if(res == 1)sum++;
    }
    cout << sum << '\n';
}