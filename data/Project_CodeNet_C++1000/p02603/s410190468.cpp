#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>a(n);
    vector<int>aa(n-1);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++){
        if(a[i+1]>a[i]){
            aa[i]=1;
        } else if(a[i+1]==a[i]) {
            aa[i]=2;
        } else {
            aa[i]=3;
        }
    }

    long long y=1000, k=0;

    for(int i=0; i<n-1; i++){
        if(aa[i]==1){
            k += y/a[i];
            y -= a[i]*(y/a[i]);
        } 
        if(aa[i]==3){
            y += k*a[i];
            k=0;
        }
    }

    y += k*a[n-1];

    cout << y << endl;

    return 0;
}
