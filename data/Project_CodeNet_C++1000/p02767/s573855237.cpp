#include <bits/stdc++.h>

using namespace std;

int dist(int p,vector<int> &x)
{
    int ret = 0;
    for (int i = 0; i < (int)x.size(); ++i) {
        ret += abs(x[i]-p)*abs(x[i]-p);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int > x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    
    int l_ = *min_element(x.begin(),x.end());
    int r_ = *max_element(x.begin(),x.end());
    //int p = (r_-l_ & 1 ? r_-l_-1 : r_-l_);
    //int p_opt = p;
    int p = l_;
    vector<int> v;
    for (p; p <= r_; ++p) {
        v.emplace_back(dist(p,x));
    }
    cout << *min_element(v.begin(),v.end()) << "\n";
}
