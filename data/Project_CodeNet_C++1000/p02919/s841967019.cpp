#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
const ll INF=1000000000;

int main(){
    ll N;
    cin>>N;
    vector<ll> P(N);
    for(ll i=0; i<N; i++){
        cin>>P[i];
        P[i] --;
    }
    vector<ll> Q(N);//iのある場所

    for(ll i=0; i<N; i++){
        Q[P[i]]=i;
    }

    set<ll> index;
    ll Ans=0;
    for(ll i=N-1; i>=0; i--){
        ll Place;
        Place=Q[i];
        ll c=0;
        index.insert(Place);
        vector<ll> low(2, -1);
      	vector<ll> high(2, N);
       	auto fi=index.find(Place);
        for(ll j=0; j<2; j++){
            if(index.begin()==fi)break;
            fi --;
            low[j]=*fi;
        }
        fi=index.find(Place);
        for(ll j=0; j<2; j++){
            fi ++;
            if(index.end()==fi)break;
            high[j]=*fi;
          	//cout<<"!";
        }
        c=(high[0]-Place)*(low[0]-low[1])+(high[1]-high[0])*(Place-low[0]);
        Ans+=c*(i+1);
      	//cout<<high[1]<<" "<<high[0]<<" "<<Place<<" "<<low[0]<<" "<<low[1]<<endl;
      	//cout<<c<<endl;
    }
    cout<<Ans<<endl;
    return 0;


}