#include<iostream>
using namespace std;
const int N = 1e7 + 5;
int a[N];
int main(){
    int n;
    cin >> n;
    
    long long ans = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j*i <= n ; j++ ){
            a[i*j]++;
        }
        ans += ( (long long)i * a[i] ); 
    }

    cout << ans;
}