#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>cnt(n,0);
    for(int i=1;i<n;i++)cin >> a[i];
    
    for(int i=1;i<n;){
        cnt[a[i]-1]++;
        i++;
    }
    
    for(int i=0;i<n;i++) cout << cnt[i] << endl;
    
    return 0;
}
