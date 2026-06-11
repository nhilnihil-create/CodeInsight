#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n-1;i++){
        int x;cin>>x;
        a[x-1]++;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }


    return 0;
}
