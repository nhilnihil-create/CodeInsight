#include<bits/stdc++.h>

using namespace std;

map<int,int> frequency; 
bool divisibleSieve[(int)1e6+1];

int f() {
    memset(divisibleSieve, true, sizeof(divisibleSieve));
    auto last = frequency.rbegin();
    for(auto& x:frequency){
        if(!divisibleSieve[x.first]) continue;
        for(int i = 2*x.first; i <= last->first; i += x.first){
            divisibleSieve[i] = false;
        }
    }
    int ans = 0;
    for(auto& x:frequency){
        if(divisibleSieve[x.first] && x.second == 1){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int aux;
    for(int i = 0; i < n; ++i){
        cin >> aux;
        frequency[aux]++;
    } 
    cout << f();
    return 0;
}