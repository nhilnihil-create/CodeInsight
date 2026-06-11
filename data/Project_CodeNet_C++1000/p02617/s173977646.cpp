#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long A=N*(N+1)*(N+2)/6;
    for(int i=0;i<N-1;i++){
        long long S,G;
        cin>>S>>G;
        A-=min(S,G)*(N-max(S,G)+1);
    }
    cout<<A<<endl;
}