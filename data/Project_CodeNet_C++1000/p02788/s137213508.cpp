#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair <long int, long int>

int main(){
    long int n, d, a;
    cin >> n >> d >> a;
    P x[n];
    rep(i, n) cin >> x[i].first >> x[i].second;
    sort(x, x + n);
    queue<P> que;
    P p;
    p.first = x[0].first + d;
    long int attack;
    if(x[0].second % a == 0) attack = x[0].second / a;
    else attack = x[0].second / a + 1;
    p.second = attack;
    que.push(p);
    long int ans = attack;
    for (long int i = 1; i < n; i++){
        while (!que.empty() && que.front().first + d < x[i].first){
            attack -= que.front().second;
            que.pop();
        }
        long int hp = x[i].second - attack * a;
        if (!que.empty()){
            long int hp = x[i].second - attack * a;
            if (hp > 0){
                if(hp % a == 0) {
                    attack += hp / a;
                    que.push(P(x[i].first+d, hp/a));
                    ans += hp / a;
                }else {
                    attack += hp / a + 1;   
                    que.push(P(x[i].first+d, hp/a+1));
                    ans += hp / a + 1;
                }
            }
        }else{
            if(hp % a == 0) {
                attack += hp / a;
                que.push(P(x[i].first+d, hp/a));
                ans += hp / a;
            }else {
                attack += hp / a + 1;   
                que.push(P(x[i].first+d, hp/a+1));
                ans += hp / a + 1;
            }
        }
        // cout << hp << endl;
    }
    cout << ans << endl;
}
