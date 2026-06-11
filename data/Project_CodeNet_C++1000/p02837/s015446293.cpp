#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
long long n;
vector<bool> honest(15, true);
vector<vector<pair<long long, bool> > > a(15);
long long maxv = 0;

int main(){
    cin >> n;

    for(long long i = 0; i < n; i++){
        long long A;
        cin >> A;
        for(long long j = 0; j < A; j++){
            long long x, y;
            cin >> x >> y;
            x--;
            if(y == 1){
                a[i].push_back(make_pair(x, true));
            }
            else{
                a[i].push_back(make_pair(x, false));
            }
        }
    }

    long long maxv = 0;

    for(long long bit = 0; bit < (1 << n); bit++){
        for(long long mask = 0; mask < n; mask++){
            if(bit & (1 << mask)){
                honest[mask] = true;
            }
            else{
                honest[mask] = false;
            }
        }
        long long count = 0;
        bool flag = true;
        for(long long i = 0; i < n; i++){
            if(honest[i] == true){
                count++;
                for(long long j = 0; j < a[i].size(); j++){
                    if(a[i][j].second != honest[a[i][j].first]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag == true){
            maxv = max(maxv, count);
        }
    }

    cout << maxv << endl;
    
    return 0;
}