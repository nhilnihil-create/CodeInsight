#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<vector<pair<long long, bool> > > a(n);

    for(long long i = 0; i < n; i++){
        long long A;
        cin >> A;

        for(long long j = 0; j < A; j++){
            long long x, y;
            cin >> x >> y;
            if(y == 1) a[i].push_back(make_pair(x-1, true));
            else a[i].push_back(make_pair(x-1, false));
        }
    }

    vector<bool> honest(n);
    long long maxv = 0;
    for(long long bit = 0; bit < (1 << n); bit++){
        long long cnt = 0;
        for(long long mask = 0; mask < n; mask++){
            if(bit & (1 << mask)) honest[mask] = true, cnt++;
            else honest[mask] = false;
        }

        bool flag = true;
        for(long long i = 0; i < n; i++){
            if(honest[i] == true){
                for(long long j = 0; j < a[i].size(); j++){
                    if(a[i][j].second != honest[a[i][j].first]){
                        flag = false;
                        break;
                    }
                }
            }
        }

        if(flag == true) maxv = max(maxv, cnt);
    }

    cout << maxv << endl;
    return 0;
}