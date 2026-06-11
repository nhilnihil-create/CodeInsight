#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll INF=300000;
//ll MAX_N=510;
//ll MAX_A=1000100;
//ll PrimeListMax=0;
//vector<ll> PrimeList(10000, 0);
vector<ll> YakuList(0);
//vector<ll> Prime(0);

int main(){
    ll N, K;
    cin>>N>>K;
    vector<ll> A(N);
    ll Sum=0;
    for(int i=0; i<N; i++){
        cin>>A[i];
        Sum+=A[i];
    }
  	//cout<<"Sum="<<Sum<<endl;
    ll RtSum=pow(Sum, 0.5);
  	//cout<<"RtSum="<<RtSum<<endl;
    ll YakuCou=0;
    bool Half=false;
    if(Sum==RtSum*RtSum){
        YakuList.push_back(RtSum);
        Half=true;
        YakuCou++;
    }
    for(ll i=1; i<=RtSum; i++){
        if(i==RtSum&&Half)break;
        if(Sum%i==0){
            YakuCou +=2;
            YakuList.push_back(i);
            YakuList.push_back(Sum/i);
          	//cout<<i<<endl<<Sum/i<<endl;
        }
    }
    ll Max=1;
    for(ll i=0; i<YakuCou; i++){
        vector<ll> B(N);
        ll BSum=0;
        for(ll j=0; j<N; j++){
            B[j]=A[j]%YakuList[i];
            BSum+=B[j];
        }
        sort(B.begin(), B.end());
        BSum/=YakuList[i];
        ll Cnt=0;
        for(ll j=0; j<BSum; j++){
            Cnt += -1*(B[N-1-j]-YakuList[i]);
        }
        if(Cnt<=K){
            Max=max(Max, YakuList[i]);
        }
        
    }
	cout<<Max<<endl;
    return 0;

}