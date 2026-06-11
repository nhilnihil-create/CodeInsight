#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n ;
    vector<int>bas(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> bas.at(i);
        sum+=bas.at(i);
    }
    int x=round(double(sum)/n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=pow(bas.at(i)-x,2);
    }
    cout << ans << endl;
    return 0;
}