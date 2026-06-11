#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n,i,cnt=0;
    cin >> n;
    vector<int>a(n);
    for(i=0;i<n;i++) cin >> a[i];
    for(i=1;i<n-1;i++){
        if(a[i-1]<a[i] && a[i]<a[i+1] || a[i-1]>a[i] && a[i]>a[i+1]) cnt++;
    }
    cout << cnt << endl;
}