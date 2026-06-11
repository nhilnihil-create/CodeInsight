#include<iostream>
#include<set>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=1;
    long long m=0;
    while(ans<=n){
       m=(10*m+7)%n;
//        cout<<m<<endl;
        if(m%n==0) break;
        ans++;
    }
    if(ans<=n)
        cout<<ans;
    else cout<<-1;
    return 0;
}
