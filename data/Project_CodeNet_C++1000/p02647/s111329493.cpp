#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int times = 0;
    bool flag = true;

    while(flag == true && times < k){
        vector<int> a_new(n+1);
        flag = false;
        times += 1;

        for(int i=0; i<n; i++){
            int l = max(0, i-a[i]);
            int r = min(n-1,i+a[i]);
            a_new[l] += 1;
            a_new[r+1] -= 1;
        }
        for(int i=0; i<n; i++){
            a_new[i+1] += a_new[i];
        }
        for(int i=0; i<n; i++){
            if(a_new[i] != a[i]) flag = true;
            //cout << a_new[i] << " ";
        }
        //cout << endl;
        a = a_new;
    }

    for(int i=0; i<n; i++){
        cout << a[i];
        if(i == n-1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}