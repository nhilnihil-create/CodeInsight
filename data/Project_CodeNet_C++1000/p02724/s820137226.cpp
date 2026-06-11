#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int x;
    cin>>x;
    int count500=x/500;
    int count5=(x-500*count500)/5;
    cout<<count500*1000+count5*5<<endl;
}