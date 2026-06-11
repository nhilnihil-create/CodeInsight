#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()
const int mod=1e9+7;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> a={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;cin>>k;
    cout<<a[k-1]<<endl;
    return 0;
}
