#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> p(n);
    for(int i=0;i<n;++i){
        long long a,b;
        cin>>a>>b;
        p[i]=make_pair(b,a);
    }
    
    sort(p.begin(),p.end());
    long long sum=0;
    for(int i=0;i<n;++i){
        sum+=p[i].second;
        if(sum>p[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}