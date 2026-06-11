#include <bits/stdc++.h>
using namespace std;

//n
int main() {
    int n;
    cin >> n;
    vector<long long>a(n + 1);
    vector<long long>b(n);
    for(int i = 0;i < n + 1;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    long long count = 0;
    for(int i = 0;i < a.size();i++){
        if(i != 0){
            if(a[i] >= b[i - 1]){
                a[i] -= b[i - 1];
                count += b[i - 1];
                b[i - 1] = 0;
            }else{
                b[i - 1] -= a[i];
                count += a[i];
                a[i] = 0;
            }
        }
        if(i != a.size() - 1){
            if(a[i] >= b[i]){
                a[i] -= b[i];
                count += b[i];
                b[i] = 0;
            }else{
                b[i] -= a[i];
                count += a[i];
                a[i] = 0;
            }
        }
    }
    cout << count;
}