#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
 
int N,K;

int main(void)
{
    cin >> N >>K;
    vector<int> H(N);
    for(int a=0;a<N;a++){
        cin >> H[a];
    }
    sort(H.begin(),H.end(),std::greater<int>());
    ll ans=0;
    for(int a=0;a<N;a++){
        if(a<K){
            //ans++;
        }else{
            ans+=H[a];
        }
    }
    cout << ans << endl;
}
