#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)


int main(){
    int N,K,Q;
    cin >> N >> K >> Q;
    map<int ,int> mp;
    rep(i,Q){
        int a;
        cin >> a;
        mp[a-1] +=1;
    }
    rep(i,N){
        if(K-(Q-mp[i])>0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}