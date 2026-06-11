#include <bits/stdc++.h>
using namespace std;

int main() {
long long ans = 0;
long long N,D,A;
cin >> N >> D >> A;
vector<vector<long long>> enemies(N, vector<long long> (2));
for (int i = 0; i < N; i++)
{
    cin >> enemies.at(i).at(0) >> enemies.at(i).at(1);
}
sort(enemies.begin(),enemies.end(),[](const vector<long long> &alpha,const vector<long long> &beta){return alpha[0] < beta[0];});

queue<vector<long long>> damage;
long long dmg = 0;
for (int i = 0; i < N; i++){
    long long x = enemies.at(i).at(0);
    long long h = enemies.at(i).at(1);
    if (damage.empty()){
        long long bomb = (h+A-1)/A;
        ans += bomb;
        dmg += bomb*A;
        damage.push({x+2*D,bomb});
    }
    else{
        while (!damage.empty()){
            vector<long long> vec;
            vec = damage.front();
            long long d = vec.at(0);
            long long bomb = vec.at(1);
            if (d < x){
                dmg -= bomb*A;
                damage.pop();
            }
            else{
                break;
            }
        }
        if (h > dmg){
            long long bomb = (h-dmg+A-1)/A;
            dmg += bomb*A;
            damage.push({x+2*D,bomb});
            ans += bomb;
        }
    }
}

cout << ans << endl;
}