#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n-1,vector<int>(0));
    rep(i,n-1){
        rep(j,n-i-1){
            int k=1,t=j+1;
            while(true){
                if (t%2==1) break;
                t/=2;
                k++;
            }
            a.at(i).push_back(k);
        }
    }
    rep(i,n-1){
        rep(j,a.at(i).size()-1) cout << a.at(i).at(j) << " ";
        cout << a.at(i).at(a.at(i).size()-1) << endl;
    }
}
