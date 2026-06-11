#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    REP(i,n){
        cin >> vec[i];
    }
    int count = 0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if((vec[i]!=vec[j])&&(vec[j]!=vec[k])&&(vec[k]!=vec[i])){
                    int max1 = max({vec[i],vec[k],vec[j]});
                    int sum = vec[i]+vec[k]+vec[j];
                    if(2*max1-sum<0){
                        count++;
                    }
                }
            }
        }
    }
    COUT(count);
}
