#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    long long N;
    long long mx=0;
    vector<long long> input;
    while(cin>>N){
        if(N==0) break;
        input.push_back(N);
        mx = max(mx,N);
    }

    mx = mx * 2+1;
    vector<bool> sosu(mx+1,true);
    sosu[1] = false;
    sosu[2] = true;
    sosu[3] = true;

    for(long long i=2;i*i<=mx;i++){
        if(sosu[i]==false) continue;
        for(long long j=2;i*j<=mx;j++){
            sosu[i*j]=false;
        }
    }

    for(long long ii=0;ii<input.size();ii++){
        N = input[ii];
        long long cnt1 = 0;
        for(long long i=1;i<=N;i++) if(sosu[i]) cnt1++;
        long long cnt2 = 0;
        for(long long i=1;i<=2*N;i++) if(sosu[i]) cnt2++;
        cout << cnt2 - cnt1 << endl;
    }
}