#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int n,k,a[200000];
    int distant = 0;
    int distance;
    cin >> k >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        distance = min( abs(a[i]-a[(i+1)%n]), k-abs(a[i]-a[(i+1)%n]) );
        distant = max( distant, distance);
    }
    cout << k-distant;

}