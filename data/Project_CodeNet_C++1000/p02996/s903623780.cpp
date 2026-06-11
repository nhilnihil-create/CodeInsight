#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int N;
    cin >> N;
    vector<P>AB(N);
    rep(i, 0, N){
        cin >> AB[i].first >> AB[i].second;
    }
    sort(AB.begin(), AB.end(), [](const P& x , const P& y) { return x.second < y.second;});
    ll d = 0;
    bool isok = true;
    rep(i, 0, N){
        d+=AB[i].first;
       
        if(d>AB[i].second){
            isok = false;
        }
    }
    if(isok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
