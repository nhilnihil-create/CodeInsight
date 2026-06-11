#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x;
    cin >> x;
    int n = 100300;
    vector<int> seive(100301);
    for(int i=2; i*i<=n; i++){
        int cnt = 2;
        while(i*cnt <= n){
            seive[i*cnt]++;
            cnt++;
        }
    }
    vector<int> prime;
    for(int i=2; i<n; i++){
        if(seive[i]==0) prime.push_back(i);
    }
    auto itr = lower_bound(prime.begin(),prime.end(),x);
    cout << *itr << endl;
    return 0;
}