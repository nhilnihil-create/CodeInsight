#include <iostream>
#include <functional>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    int d[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n);
    int count = n/2;
    int ans = d[count]-d[count-1];
    cout<<ans<<endl;
}
