#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n+1);
    vector<long long> b(n);
    long long sum=0;
    for (int i=0; i<n+1; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];
    for (int i=0; i<n; i++){
        if (a[i]<b[i]){
            if (a[i+1]<(b[i]-a[i])){
                sum+=a[i+1];
                a[i+1] = 0;
            }
            else {
                a[i+1] -= b[i]-a[i];
                sum+=b[i]-a[i];
            }
            sum+=a[i];
        }
        else sum+=b[i];
    }
    cout<<sum<<endl;
}
