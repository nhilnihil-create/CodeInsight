#include <iostream>

using namespace std;
long long sum,digits;
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long d,c;
        cin>>d>>c;
        sum+=d*c;
        digits+=c;
    }
    cout<<digits-1 +((sum-1)/9)<<endl;
}
