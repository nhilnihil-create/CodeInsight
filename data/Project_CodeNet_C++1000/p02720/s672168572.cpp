#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

vector<int> a;
void addd(int d){
    if(d==a.size()) a.push_back(1);
    else a[d]++;

    if(a[d]==10 ||
        d!=a.size()-1 && abs(a[d]-a[d+1])>1){
        a[d]=0;
        addd(d+1);
        a[d]=max(0, a[d+1]-1);
    }
}

int main(){
    int k;
    cin>>k;

    rep(i, k){
        addd(0);
    }
    for(auto it=a.rbegin(); it!=a.rend(); it++) cout<<(*it);
    cout<<endl;

    return 0;
}
