#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    int ans=1000000007;
    for(int j=0;j<n;j++){
        cin >> x.at(j);
    }
    for(int i=1;i<101;i++){
        int tmp=0;
        for(int j=0;j<n;j++){
            tmp+=(x.at(j)-i)*(x.at(j)-i);
        }
        if(ans>tmp)ans=tmp;
    }
    cout << ans << endl;
    return 0;
}