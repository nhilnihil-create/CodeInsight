#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    if(k > 50){
        k = 50;
    }
    int b[k][n] = {};
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int h=0;h<k;h++){
        for(int i=0;i<n;i++){
            if(i-a[i]>0){
                b[h][i-a[i]] += 1;
            }else{
                b[h][0] += 1;
            }
            if(i+a[i]+1<n)
                b[h][i+a[i]+1] -= 1;
        }
        a[0] = b[h][0];
        for(int i=1;i<n;i++){
            a[i] = a[i-1] + b[h][i];
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }


}