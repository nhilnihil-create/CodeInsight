#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n,0),y(n,0);
    for (int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        x[i]=a;
        y[i]=b;
    }
    map<vector<ll>,vector<vector<ll>>> test;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i<j) {
                ll dx,dy;
                ll st,ed;
                if (x[j]-x[i]>0) {
                    dx = x[j]-x[i];
                    dy = y[j]-y[i];
                    st = i;
                    ed = j;
                }
                else if (x[i]==x[j]) {
                    if (y[j]-y[i]>0) {
                        dx = 0;
                        dy = y[j]-y[i];
                        st = i;
                        ed = j;
                    }
                    else {
                        dx = 0;
                        dy = y[i]-y[j];
                        st = j;
                        ed = i;
                    }
                }
                else {
                    dx = x[i]-x[j];
                    dy = y[i]-y[j];
                    st = j;
                    ed = i;
                }
                vector<ll> tempv = {dx,dy};
                test[tempv].push_back({st,ed});
            }            
        }
    }

    map<vector<ll>,vector<vector<ll>>> test2;
    for(auto tt:test) {
        bool flag = true;
        while (flag) {
            flag = false;
            bool change = false;
            for (auto testi = tt.second.begin();testi != tt.second.end();testi++) {
                if (change) break;
                for (auto testj = tt.second.begin();testj != tt.second.end();testj++) {
                    if (testi<testj) {
                        if ((*testi).back()==(*testj).front()) {
                            copy((*testj).begin()+1,(*testj).end(),back_inserter(*testi));
                            tt.second.erase(testj);
                            change = true;
                            flag = true;
                            break;
                        }
                        if ((*testi).front()==(*testj).back()) {
                            copy((*testi).begin()+1,(*testi).end(),back_inserter(*testj));
                            tt.second.erase(testi);
                            change = true;
                            flag = true;
                            break;
                        }
                    }                    
                }
                
            }
        }
        test2[tt.first] = tt.second;    
    }

    ll g = 999999;
    for(auto tt:test2) {
        ll ttsize = tt.second.size();
        ll usePoint = 0;
        for(auto ttt2:tt.second) {
            for(auto p=ttt2.begin();p!=ttt2.end();p++) {
                usePoint++;
            }
        }
        g = min(g, ttsize + n-usePoint);
    }
    if (n==1) cout << 1 << endl;
    else cout << g << endl;
    return 0;
}