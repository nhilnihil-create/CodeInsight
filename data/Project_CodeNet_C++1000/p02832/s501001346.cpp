#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N; cin>>N;
    vi a(N);
    for (int i = 0; i < N; i++)cin>>a[i];
    int ans=0;
    int i=1,index=0;
    while(index<N){
        if(i==a[index]){
            i++;
            index++;
        }else{
            index++;
            ans++;
        }
    }
    if(ans==N)ans=-1;
    cout<<ans<<endl;
}