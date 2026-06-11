#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    
    vector<pair<int,int>> robot;
    rep(i,N){
        int x,l;
        cin >> x >> l;
        robot.push_back(pair(x+l,x-l));
    }
    
    sort(robot.begin(), robot.end());
    
    int ans=1;
    int now=robot[0].first;
    
    for (int i = 1; i < N; i++) {
        int y = robot[i].second;
        if(y>=now){
            now = robot[i].first;
            ans++;
        }
    }
    
    cout << ans << endl;
    
    // rep(i,N){
    //     int x,y;
    //     x = robot[i].first;
    //     y = robot[i].second;
    //     cout << x << " " << y << endl;
    //}
}
