#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    long long int n,a=7,ans=-1;
    cin>>n;
for(long long int i=0;i<=n;i++){
        if(a%n==0){
            ans=i+1;
            break;
        }
        else{
            a=(a*10+7)%n;
        }
    }
    cout<<ans<<endl;
    return 0;
}
