#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n,vector<int>(d));
    rep(i,n)rep(j,d) cin >> x.at(i).at(j);
    int count=0;
    rep(i,n-1){
        for(int j=i+1;j<n;j++){
            int dis_2=0;
            rep(k,d){
                dis_2+=(x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
            }
            double dis=sqrt(dis_2);
            int intdis=dis;
            if(intdis==dis) count++;

        }
    }
    cout << count << endl;

}