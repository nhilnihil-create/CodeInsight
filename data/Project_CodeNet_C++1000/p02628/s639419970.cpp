#include<bits/stdc++.h>
using namespace std;
int main(void){
    int N,K;
    cin>>N>>K;
    vector<int>p(N);
    for(int i=0;i<N;i++){
        cin>>p[i];
    }
    for(int i = 0;i<N-1;i++){
        for(int j =i;j<N;j++){
            int buf;
            if(p[i]>p[j])swap(p[i],p[j]);
        }
    }
    int ans =0;
    for(int i=0;i<K;i++){
        ans += p[i];
    }

    cout<<ans<<endl;

    return 0;
}