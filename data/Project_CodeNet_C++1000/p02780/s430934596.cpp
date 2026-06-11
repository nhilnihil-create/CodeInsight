#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin >> n >> k;
    vector<double> p(n);
    for(int i=0; i<n; i++){
        cin >> p.at(i);
    }
    
    double ans=0;
    for(int i=0; i<k; i++){
        ans+=p.at(i);
    }
    double num=ans;

    for(int i=0; i<n-k; i++){
        num=num-p.at(i)+p.at(k+i);
        ans=max(ans,num);
    }

    ans=(ans+k)/2;
    cout << fixed << setprecision(9) << ans << endl;
}