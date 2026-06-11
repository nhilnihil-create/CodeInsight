#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> num(200001,0);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        num.at(a.at(i))++;
    }

    long long int count=0;
    for(int i=1; i<200001; i++){
        count+=num.at(i)*(num.at(i)-1)/2;
    }
    
    long long int ans;
    for(int i=0; i<n; i++){
        ans=count-num.at(a.at(i))+1;
        cout << ans << endl;
    }
}