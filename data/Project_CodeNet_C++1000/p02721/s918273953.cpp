
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_set>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;




using namespace std;




int main(){
    ll N,K,C;
    cin>>N>>K>>C;
    string st;
    cin>>st;
    vector<ll> vec1,vec2;
    ll count=0;
    for(ll i=0;i<N;++i){
        if(count>K)break;
        if(st[i]=='o'){
            vec1.push_back(i);
            i=i+C;
            ++count;
        }
      
    }
    /*for(int i=0;i<vec1.size();++i){
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    */
    count=0;
    for(ll i=N-1;i>=0;--i){
        if(count>K)break;
        if(st[i]=='o'){
            vec2.push_back(i);
            i=i-C;
            ++count;
        }
        
     
    }
    sort(vec2.begin(),vec2.end());
   /*for(int i=0;i<vec2.size();++i){
        cout<<vec2[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=0;i<vec1.size();++i){
        if(vec1[i]==vec2[i]){
            cout<<vec1[i]+1<<endl;
        }
    }
}



