/*
      author : Nishikawa
      created: 05.08.2020 16:15:21
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int N;
    cin >> N;
    vector<ll> vec(N+1);
    for(int i=1; i<=N; i++) cin >> vec[i];
    sort(vec.begin()+1,vec.end(),greater<int>());

    ll sum=0;
    if(N==2) sum=vec[1];
    else{
        if(N%2==0){
            sum+=vec[1];
            for(int i=2; i<=N/2; i++) sum+=2*vec[i];
        }
        else{
            sum+=vec[1];
            for(int i=2; i<=(N-1)/2; i++) sum+=2*vec[i];
            sum+=vec[(N-1)/2+1];
        }
    }
    cout << sum << endl;
    return 0;
}