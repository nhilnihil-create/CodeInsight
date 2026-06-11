#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int u, v;
    long long int x = 0, y = 0;
    for(int i = 0; i<n-1; i++){
        cin >> u >> v;
        x = x + (long long int)min(u,v) * (n - max(u, v) + 1);
        y = y + (long long int)(i + 1) * (n - i);
    }
    cout << y + n - x;
}