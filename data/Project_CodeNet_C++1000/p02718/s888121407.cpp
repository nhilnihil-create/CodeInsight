#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int sum = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    if(a[m-1] < sum/(double)(4*m)) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}