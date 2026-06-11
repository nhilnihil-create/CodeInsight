#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> L(N);
    for(int i=0; i<N; ++i) cin>>L[i];

    int ans=0;
    vector<int> v(3);
    for(int i=0; i<N-2; ++i){
        for(int j=i+1; j<N-1; ++j){
            if(L[i]==L[j]) continue;
            for(int k=j+1; k<N; ++k){
                if(L[i]==L[k] || L[j]==L[k]) continue;
                v[0]=L[i];
                v[1]=L[j];
                v[2]=L[k];
                sort(v.begin(), v.end());
                if(v[0]+v[1]>v[2]) ++ans;
            }
        }
    }
    cout<<ans<<endl;
}
