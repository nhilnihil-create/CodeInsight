#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int> > vec(N);
    rep(i,N){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(all(vec));
    priority_queue<int> pque;
    rep(i,100005){
        pque.push(0);
    }
    int count = 0;
    int ans = 0;
    for (int i = 1; i <= M; i++){
        while(true){
            if (count >= N){
                break;
            }
            else if (vec[count].first != i){
                break;
            }
            else{
                pque.push(vec[count].second);
                count++;
            }
        }
        ans += pque.top();
        pque.pop();
    }
    cout << ans << endl;
}
