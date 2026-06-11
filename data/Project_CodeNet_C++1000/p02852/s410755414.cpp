#include<bits/stdc++.h>
//#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> stops(1,n);
    int where=n;
    while(where){
        bool next=false;
        for(int i=max(0,where-m); i<where; i++){
            if(s.at(i)=='0'){
                where=i;
                stops.push_back(i);
                next=true;
                break;
            }
        }
        if(!next){
            cout << -1 << endl;
            return 0;
        }
    }
    //int s=stops.size()-1;
    vector<int> ans(stops.size()-1);
    for(int i=0; i<stops.size()-1; i++){
        ans.at(i)=stops.at(i)-stops.at(i+1);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i<stops.size()-1; i++){
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}