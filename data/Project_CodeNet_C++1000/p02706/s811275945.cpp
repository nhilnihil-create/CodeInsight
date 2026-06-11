#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];

    long long sum=accumulate(a.begin(),a.end(),0LL);
    if(sum>n){
        cout<<-1<<endl;
    }
    else{
        cout<<n-sum<<endl;
    }

    return 0;
}
