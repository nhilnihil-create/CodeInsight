#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
typedef long long ll;

int main() {
    int N;
    cin>>N;
    vector<pair<ll,ll> > vp;
    for(int i=0;i!=N;++i){
        ll a,b;
        cin>>a>>b;
        
        vp.push_back(make_pair(a,b));
    }
    
    sort(vp.begin(),vp.end(),[](pair<ll,ll> p1,pair<ll,ll> p2){
        return p1.second <p2.second;
    });
    /*
    for(int i=0;i!=N;++i){
        cout<<vp[i].first<<":"<<vp[i].second<<endl;;
    }
    */
    ll sum=0;
    bool flag=true;
    //cout<<"--------------------------"<<endl;
    
    for(int i=0;i<N;++i){
        sum+=vp[i].first;
        //cout<<sum<<":"<<vp[i].second<<endl;
        if(sum>vp[i].second){
            flag=false;
            break;
        }
    }
    
    if(flag==true){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}
