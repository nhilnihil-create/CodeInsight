#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int n, k, c;
    cin>>n>>k>>c;
    string s;
    cin>>s;

    vector<int> w1(k), w2(k);
    for(int i=0, p=0; i<k; i++){
        while(s[p]=='x') p++;
        w1[i]=p;
        p += c+1;
    }

    for(int i=k-1, p=n-1; i>=0; i--){
        while(s[p]=='x') p--;
        w2[i]=p;
        p -= c+1;
    }

    rep(i, k) if(w1[i]==w2[i]) cout<<(w1[i]+1)<<endl;

    return 0;
}
