#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n,i,sum=0;
    cin >> n;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    int ans=sum,g=0;
    for(i=0;i<n;i++){
        g+=a[i];
        sum-=a[i];
        ans = min(ans,std::abs(sum-g));
    }
    cout << ans;
}