#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<pair<long long, long long> > v;

    for(long long i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    map<pair<long long, long long>, long long> T;
    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            long long dx = v[j].first - v[i].first;
            long long dy = v[j].second - v[i].second;
            if(dx < 0){
                dx = -dx;
                dy = -dy;
            }
            else if(dx == 0){
                if(dy < 0){
                    dy = -dy;
                }
            }
            
            if(T.find(make_pair(dx, dy)) == T.end()){
                T[make_pair(dx, dy)] = 1;
            }
            else{
                T[make_pair(dx, dy)]++;
            }
        }
    }

    map<pair<long long, long long>, long long>::iterator it;
    long long maxv = 0;
    for(it = T.begin(); it != T.end(); it++){
        maxv = max(maxv, it->second);
    }

    cout << n - maxv << endl;
    return 0;
}