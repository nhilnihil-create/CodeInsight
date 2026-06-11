#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(void){
    
    int N;
    vector<pair<long long, long long>> v;
    long long x,l;
    cin >> N;
    int mx;
    for(int i = 0; i < N;i++){
        cin >> x >> l;
        v.push_back(make_pair(x-l,x+l));
    }
    
    sort(v.begin(),v.end(),compare_by_b);
    mx = v[0].second;
    v.erase(v.begin());
    
    int cont = 0;
    
    for(auto u:v){
        
        //cout  << u.first <<" "<<mx;
        if(u.first<mx){cont++;}
        else{mx = u.second;}

    }
    
    cout << v.size() + 1 -cont << endl;    
    
}
