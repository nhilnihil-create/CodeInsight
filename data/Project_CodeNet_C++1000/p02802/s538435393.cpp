#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;


int main(){
    int N,M;
    cin >> N >> M;
    vector<int> cnt(N,0),flag(N,0);
    for(int i=0; i<M; i++){
        int p;string s;
        cin >> p >> s;
        p--;
        if(s=="WA" && flag[p]==0){
            cnt[p]++;
        }else{
            flag[p]=1;
        }
    }

    int wa=0,ac=0;
    for(int i=0; i<N; i++){
        if(flag[i]==1){
            ac++;
            wa+=cnt[i];
        }
    }

    cout << ac << ' ' << wa << endl;




    return 0;
}