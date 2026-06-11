#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    int ans=0;
    int sum=0;
    for (int i = 0; i < N; i++){
        int d; cin>>d;
        sum+=d;
        ans-=d*d;
    }
    cout<<(ans+sum*sum)/2<<endl;
}