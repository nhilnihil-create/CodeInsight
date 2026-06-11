#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    ll A,B,K;cin>>A>>B>>K;
    cout<<max((ll)0,A-K)<<" "<<max((ll)0,B-max(K-A,(ll)0))<<endl;
}