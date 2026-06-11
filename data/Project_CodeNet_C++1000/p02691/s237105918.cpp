#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int a[n], x;
    ll ans=0;
    vector<int> p[n], m[n];
    rep(i, n){
        cin >> a[i];
        //cout << a[i] << " ";
    }
    rep(i, n){
        //if(i+a[i]<n) p[i+a[i]].append(i);
        if(i-a[i]>0) m[i-a[i]].push_back(i);
    }
    rep(i, n){
        //sort(p[i].begin(),p[i].end());
        sort(m[i].begin(),m[i].end());
    }

    rep(i, n){
        //cout <<"i+a[i]"<<i+a[i]<<endl;
        if(i+a[i]<n){
            x = i+a[i];
            //cout << "x fixed"<<endl;
        }
        else continue;
        //cout << "x="<<x<<endl;
        int y = 0;
        if(y == m[x].size()) continue;
        //cout << "!"<< endl;
        while(m[x][y] < i){
            y++;
            if(y == m[x].size()) break;
        }
        //cout << "y="<<y << endl;
        ans += m[x].size()-y;
    }
    cout << ans << endl;
}