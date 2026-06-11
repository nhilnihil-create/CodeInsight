#include <bits/stdc++.h>
using namespace std ;

int main(){
    int N;
    cin >> N;
    int W[N];
    int sum=0;
    for(int i=0;i<N;i++){
        cin >> W[i];
        sum+=W[i];
    }
    int a=0;
    int ans;
    for(int i=0;i<N;i++){
        if(i==0){
            if(sum>=2*W[0]){
                a+=W[0];
                ans=sum-2*W[0];
            }else{
                cout << W[0] << endl;
                break;
            }
        }else{
            a+=W[i];
            if(sum>=2*a){
                 ans=min(ans,sum-2*a);
            }else{
                int answer=2*a-sum;
                 ans=min(ans,answer);
                 cout << ans << endl;
                 return 0;
            }
        }
    }
    cout << ans << endl;


}