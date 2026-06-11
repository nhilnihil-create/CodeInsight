#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 10000;

int main(){
    
    int n,x,y;
    cin>>n>>x>>y;
    --x,--y;
    vector<int> d(n-1);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int t = min(abs(j-i), abs(i-x)+1+abs(y-j));
            d[t-1]++;
        }
    }
    for(int i : d) cout<<i<<"\n";
}

