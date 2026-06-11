#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,sum(0);
    cin>>n>>k;
    int x[n];
    for (int i=0;i<n;i++) cin>>x[i];
    sort(x, x+n);
    for (int i=0;i<k;i++) sum+=x[i];
    cout<<sum;
}