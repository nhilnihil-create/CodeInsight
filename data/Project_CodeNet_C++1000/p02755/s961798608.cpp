#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B; cin >> A >> B;
    int left,right;
    left=ceil(A/0.08); right=floor((A+1)/0.08);
    int ans=-1;
    for(int i=left; i<right; i++){
        if(floor(i*0.1)==B){
            ans=i;
            break;
        }
    }
    cout << ans << endl;
}
