#include <iostream>
#include<vector>

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
    vector<int>h(n);
    rep(i,n) cin>>h[i];
    for(int i = n-1; i > 0; i--) {
        if(h[i-1]-h[i]>1) {
            cout<<"No"<<endl;
            return 0;
        }
        else if(h[i-1]>h[i])
        {
            h[i-1]--;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}
