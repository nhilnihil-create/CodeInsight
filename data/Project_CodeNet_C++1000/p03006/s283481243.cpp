#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    set<pair<long long int, long long int>> ball;
    for(int i=0; i<n; i++){
        long long int x, y;
        cin >> x >> y;
        ball.insert({x,y});
    }

    vector<long long int> x, y;
    for(auto b : ball){
        x.push_back(b.first);
        y.push_back(b.second);
    }

    int ans = n;// INF
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            set<pair<long long int, long long int>> test = ball;
            long long int p = x[j] - x[i];
            long long int q = y[j] - y[i];

            int times = 0;
            for(int k=0; k<n; k++){
                long long int nx = x[k];
                long long int ny = y[k];
                if(test.find({nx,ny}) == test.end()) continue;
                while(test.find({nx+p, ny+q}) != test.end()){
                    test.erase({nx,ny});
                    nx += p;
                    ny += q;
                }
                test.erase({nx,ny});
                times += 1;
            }
            ans = min(ans, times);
        }
    }
    cout << ans << endl;
    return 0;
}