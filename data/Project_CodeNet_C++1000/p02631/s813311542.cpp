#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 5;
int main(){
    int n ;
    cin >> n;
    vector<int> a(n);
    long long xr = 0;
for(int i = 0 ; i<n;  i++){
        cin>> a[i];
        xr^=a[i];
}
    for(int i = 0 ; i<n; i++)cout<<(xr^a[i])<<" " ;
}





