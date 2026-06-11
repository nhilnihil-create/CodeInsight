#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    int count = 0;
 
    int x;
    if(total%(4*m) == 0) x = total/(4*m);
    else x = total/(4*m) + 1;
 
    for(int i = 0; i < n; i++){
        if(a[i] >= x) count++;
    }
 
    //cout << x << " " << count << " " << total << endl;
 
    if(count >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
}