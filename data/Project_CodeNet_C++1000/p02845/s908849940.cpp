#include <iostream>
#define MOD 1000000007
using namespace std;


int main(void){
    int n;
    cin>>n;
    int num[3] = {};
    long long ans=1;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int count = 0;
        for(int j=0;j<3;j++){
            if(a==num[j]){
                if(count==0) num[j] ++;
                count ++;
            }
        }
        ans *= count;
        ans %= MOD;
    }
    cout<<ans<<endl;
}