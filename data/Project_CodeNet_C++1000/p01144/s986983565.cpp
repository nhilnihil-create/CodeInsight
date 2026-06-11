#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int,int>&a, pair<int,int>& b){
    return a.second > b.second;
}

int main(){
    while(1){
        int n,m;
        cin >> n >> m;
        if(n==0) break;

        int d,p;
        vector<pair<int,int> > ex(n);
        for(int i=0; i<n; i++){
            cin >> d >> p;
            ex[i] = make_pair(d,p);
        }
        sort(ex.begin(), ex.end(), cmp);

        for(int i=0; i<n; i++){
            if(ex[i].first < m){
                m -= ex[i].first;
                ex[i].first = 0;
            }else{
                ex[i].first -= m;
                m = 0;
                break;
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            cnt += ex[i].first * ex[i].second;
        }      
        cout << cnt << endl;
    }
    return 0;
}