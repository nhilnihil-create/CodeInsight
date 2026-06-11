#include <iostream>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>p(n+1);
    rrep(i,n) cin>>p[i];
    int a = -1;
    rep(i,n) {
        if(p[i+1]-p[i]!=1) {
            if(a != -1) {
                swap(p[a],p[i+1]);
                break;
            }
            a = i+1;
            i++;
        }
    }
    rrep(i,n) {
        if(p[i] != i) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
