#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int>L(n);
    for(int i=0;i<n;i++){
        cin >> L[i];
    }
    sort(L.begin(),L.end());
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=upper_bound(L.begin()+j+1,L.end(),L[j]-L[i])-(L.begin()+j+1);
            int y=lower_bound(L.begin()+j+1,L.end(),L[i]+L[j])-(L.begin()+j+1);
            sum+=(y-x);
        }
    }
    cout << sum << endl;
}