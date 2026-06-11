#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;    

    int w[n];
    int sum=0;
    for (int i=0;i<n;i++){
        cin >> w[i];
        sum += w[i];
    }

    int ans = sum;
    int left,right;
    for(int t=0;t<n;t++){
        left += w[t];
        right = sum - left;
        ans = min(ans,abs(left-right));
    }
    cout << ans << endl;

}