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

int N;
string S;
bool C(int mid){
    map<string,vector<int> > mp;
    for(int i=0;i<N-mid+1;i++){
        mp[S.substr(i,mid)].push_back(i);
    }
    for(auto p: mp){
        vector<int> v=p.second;
        int l=v[0];
        int r=l+mid-1;
        if(v.size()>=2){
            rep(i,v.size()){
                if(i==0) continue;
                if(v[i]>r) return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> N >> S;
    int l=0,r=S.size()+1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(C(mid)) l=mid;
        else r=mid;
    }
    cout << l << endl;
}