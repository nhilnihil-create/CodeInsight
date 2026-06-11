#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;


int main()
{
    int H,N;
    cin >> H >> N;
    vector< ll > cost(H+1, -1);
    ll ans=1e13;
    ll magic[N][2];
    for(int i=0; i<N; i++){
        cin >> magic[i][0] >> magic[i][1];
        if(magic[i][0]>=H) ans=min(ans,magic[i][1]);
        else if(cost[magic[i][0]]==-1) cost[magic[i][0]]=magic[i][1];
        else cost[magic[i][0]]=min(cost[magic[i][0]],magic[i][1]);
    }

    cost[0]=0;
    for(int h=0; h<H; h++){
        if(cost[h]==-1) continue;
        for(int n=0; n<N; n++){
            if(h+magic[n][0]>=H) ans=min(cost[h]+magic[n][1],ans);
            else if(cost[h+magic[n][0]]==-1) cost[h+magic[n][0]]=cost[h]+magic[n][1];
            else{
                cost[h+magic[n][0]]=min(cost[h+magic[n][0]],cost[h]+magic[n][1]);
            }
        }
    }
    cout << ans << endl;




    return 0;
}