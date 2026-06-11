#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int maxa=-10e09;
    int minv=a[0];
    
        for(int i=1;i<n;i++){
            maxa=max(maxa,a[i]-minv);
            minv=min(minv,a[i]);
    }
    
    cout <<maxa <<endl;

    return 0;
}

