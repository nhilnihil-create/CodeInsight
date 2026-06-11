#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int n,m;
    cin>>n>>m;
    int odd=0;
    int even=0;
    if(n>=2){
        odd=n*(n-1)/2;
    }
    if(m>=2){
        even=m*(m-1)/2;
    }
    cout<<odd+even<<endl;
}