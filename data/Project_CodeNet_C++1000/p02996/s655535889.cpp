#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main() {
    ll N;
    cin >> N;
    vector<P> endTime(N);
    for(int i=0;i<N;i++){
        ll A,B;
        cin >> A >>B;
        endTime[i].first = B;
        endTime[i].second = A;
    }
    sort(endTime.begin(),endTime.end());
    ll now =0;
    for(int i=0;i<N;i++){
        // cerr <<"now=" <<now << "i=" <<i  <<"endTime="<< endTime[i].first <<"need=" <<endTime[i].second<<endl;
        if(endTime[i].first < now+ endTime[i].second){
            
            cout <<"No" << endl;
            return 0;
        }
        now += endTime[i].second;
    }

    cout <<"Yes" << endl;
    

    return 0;
}