#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int N; cin>>N;
    int Amax;
    vector<int> A(N,0);
    for (int i = 0; i < N; i++){
        cin>>A[i];
        Amax=max(Amax,A[i]);
    }
    A.push_back(10000000);
    sort(A.begin(),A.end());
    vector<bool> not_divisible(Amax+1,true);
    int ans=0;
    for (int i = 0; i < N; i++){
        int x=A[i];
        if(A[i]==A[i+1]){
            if(not_divisible[x]){
                while(x<=Amax){
                    not_divisible[x]=false;
                    x+=A[i];
                }
            }
            while(A[i]==A[i+1]){
                i++;
            }
        }else{
            if(not_divisible[x]){
                while(x<=Amax){
                    not_divisible[x]=false;
                    x+=A[i];
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}