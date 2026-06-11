#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
const int INF = 100000000;
using namespace std;

int A(int a, int b){
    return a * a + b * b;
}

int main(){
    int h, w;
    while(cin >> h >> w, h||w){
        vector<pair<pair<int,int>,int>> v;
        range(i,1,200){
            range(j,i + 1,200){
                v.emplace_back(make_pair(make_pair(i * i + j * j, i), j));
            }
        }
        sort(all(v));
        rep(i,v.size()){
            if(h * h + w * w == v[i].first.first && v[i].first.second > h){
                cout << v[i].first.second << ' ' << v[i].second << endl;
                break;
            }else if(h * h + w * w < v[i].first.first){
                cout << v[i].first.second << ' ' << v[i].second << endl;
                break;
            }
        }
    }
}