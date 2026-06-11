#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N; cin>>N;
    vector<ll> x(N),y(N);
    vector<pair<double,int>> angle(N);
    for (int i = 0; i < N; ++i) {
        cin>>x[i]>>y[i];
        angle[i].second=i;
        if(x[i]==0&&y[i]==0){
            angle[i].first=0.0;
            continue;
        }
        angle[i].first=atan2(y[i],x[i]);
        if(angle[i].first<0.0) angle[i].first=2.0*M_PI+angle[i].first;
    }

    sort(angle.begin(),angle.end());
/*
    for (int i = 0; i < N; ++i) {
        cout<<angle[i].first<<" "<<angle[i].second<<endl;
    }
    */

    double ans=0.0;


    for (int i = 0; i < N; ++i) {
        double xsum=0.0,ysum=0.0;
        double sangle=angle[i].first;
        for (int j = 0; j < N; ++j) { //選ぶ個数
            int target=i+j;
            if(target>=N) target-=N;
            xsum+=(double)x[angle[target].second]; ysum+=(double)y[angle[target].second];
            ans=max(ans,sqrt(pow(xsum,2.0)+pow(ysum,2.0)));
        }
    }

    printf("%.15f\n",ans);

    return 0;
}