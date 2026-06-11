#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N,0), B(N,0);
    vector<pair<ll,ll>> jobs(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
        jobs[i] = {B[i], A[i]};
    }

    sort(jobs.begin(), jobs.end());
    ll endTime = 0;
    bool success = true;
    for(int i = 0; i < N; i++){
        endTime += jobs[i].second;
        if(endTime > jobs[i].first){
            success = false;
        }
    }

    if(success){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
