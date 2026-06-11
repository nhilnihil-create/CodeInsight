#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<P> d;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        d.emplace_back(x,y);
    }
    vector<int> v;
    rep(i,n) v.push_back(i);
    double sum = 0;
    cout << setprecision(10);
    do{
        rep(i,n-1){
            auto p1 = d.at(v.at(i));
            auto p2 = d.at(v.at(i+1));
            double dx = abs(p2.first - p1.first);
            double dy = abs(p2.second - p1.second);
            double dis = sqrt(dx*dx + dy*dy);
            sum += dis;
        }
    }while(next_permutation(v.begin(),v.end()));
    int num = 1;
    for(int i = 1; i <= n;i++) num *= i;
    cout << sum / num << endl;
}