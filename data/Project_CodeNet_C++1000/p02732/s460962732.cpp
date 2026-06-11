#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>t(n);
    vector<long long>a(n+1,0);
    for(int i=0; i<n; i++){
        cin >> t[i];
        a[t[i]]++;
    }
    long long sum=0;
    for(int i=1; i<n+1; i++){
        if(a[i]>0) sum += a[i] * (a[i]-1) / 2;
    }
    for(int i=0; i<n; i++){
        cout << sum - a[t[i]] + 1 << endl;
    }
    return 0;
}