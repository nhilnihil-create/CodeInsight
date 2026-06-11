#include<iostream>
using namespace std;

int main(){
    long long ans=0;
    long long N;
    cin >> N;
    ans += (N*(N+1)*(N+1))/2-(N*(N+1)*(2*N+1))/6;
    long long u,v,x,y;
    long long i;
    for(i=0; i<N-1; i++){
        cin >> u >> v;
        x=min(u,v);
        y=max(u,v);
        ans -= x*(N-y+1);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}