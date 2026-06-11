#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    
    int l, r;
    cin >> l >> r;
    int ans = 2020;
    for(int i=l; i<=r-1; i++){
        if(l==0) l++;
        if(l==2019||r==2019){
            ans=0;
            break;
        }
        for(int j=l+1; j<=r; j++){
            ans = min( ans, ((i%2019)*(j%2019)%2019) );
            if(ans==0){
                goto outside;
            } 
        }
    }
    outside:
    cout << ans << endl;

    return 0;
}
