#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N, M;
    cin >> N >> M;

    vector<ll> H;
    vector< vector<int> > data(N);

    int i, j;
    for(i=0;i<N;i++){
        ll hi;
        cin >> hi;
        H.push_back(hi);
    }

    for(i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        data.at(a-1).push_back(b-1);
        data.at(b-1).push_back(a-1);
    }


    bool flag = 0;
    int count = 0;
    ll height_i, height_j;
    for(i=0;i<N;i++){
        flag = 0;
        height_i = H.at(i);
        if(data.at(i).size() == 0){count += 1;}
        for(j=0;j<data.at(i).size();j++){
            height_j = H.at(data.at(i).at(j));
            if(height_i <= height_j){flag = 0; break;}
            flag = 1;
        }
        if(flag == 1){count += 1;}

    }
    cout << count << endl;


    return 0;
}
