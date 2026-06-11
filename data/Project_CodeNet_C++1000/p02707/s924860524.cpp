#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=1; i<n; i++){
        cin>>a[i]; a[i]--;
    }

    vector<int> bu(n);
    for(int i=n-1; i>=1; i--){
        bu[a[i]]+=1;
    }

    for(int i=0; i<n; i++) cout << bu[i] << endl;
    return 0;
}
