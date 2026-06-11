#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll N;
    cin >> N;

    vector<pair<ll, ll>> job;
    for(int i=0; i<N; i++){
        ll a, b;
        cin >> a >> b;
        
        job.push_back({b, a});
    }

    sort(job.begin(), job.end());

    ll now = 0;
    for(int i=0; i<N; i++){
        now += job[i].second;

        if(now > job[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<< "Yes"  <<endl;
    return 0;
}