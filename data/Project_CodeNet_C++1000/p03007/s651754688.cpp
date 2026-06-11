#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    long long m = 0;
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a.begin(),a.end());
    if(a[0] < 0 && a[n-1] > 0){//正負
        for(int i = 0;i < n;i++){
            m += abs(a[i]);
        }
        cout << m << endl;
        int i = n-2;
        while(a[i] > 0){
            cout << a[0] << " " << a[i] << endl;
            a[0] -= a[i];
            i--;
        }
        i = 0;
        while(a[i] <= 0){
            cout << a[n-1] << " " << a[i] << endl;
            a[n-1] -= a[i];
            i++;
        }
    }else if(a[0] < 0){//負のみ
        for(int i = 0;i < n-1;i++){
            m += abs(a[i]);
        }
        m += a[n-1];
        cout << m << endl;
        int x = a[n-1];
        int y;
        for(int i = 0;i < n-1;i++){
            y = a[i];
            cout << x << " " << y << endl;
            x -= y;
        } 
    }else{//正のみ
        for(int i = 1;i < n;i++){
            m += a[i];
        }
        m -= a[0];
        cout << m << endl;
        for(int i = 1;i < n-1;i++){
            cout << a[0] << " " << a[i] << endl;
            a[0] -= a[i];
        }
        cout << a[n-1] << " " << a[0] << endl;
    }
    //cin >> n;
}