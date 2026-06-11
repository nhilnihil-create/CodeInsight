#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<iomanip>
#include<numeric>
#define rep(i,n) for(int i=0;i<n;++i)
#define mod 1000000007
using namespace std;
int main(){
    vector<pair<int,int> > map;
    while(true){
        int H,W;    cin>>H>>W;
        if(H==0&&W==0)break;
        map.push_back(make_pair(H,W));
    }
    rep(i,map.size()){
        rep(j,map[i].first){
            rep(k,map[i].second){
                if(j==0||k==0||j==map[i].first-1||k==map[i].second-1)  cout<<'#';
                else    cout<<'.';
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
