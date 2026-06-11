#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    vector<int> L(N);
    cin>>N;
    for(int i=0; i<N; i++) cin>>L[i];

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(L[i] != L[j] && L[i] != L[k] && L[j]!= L[k]){
                    if(L[i] + L[j] > L[k] && L[j] + L[k] > L[i] && L[i] + L[k] > L[j]) ans++;
                }
            }
        }
    }

    cout<<ans<<endl;
}