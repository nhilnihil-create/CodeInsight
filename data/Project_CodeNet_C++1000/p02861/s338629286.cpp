#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    ll N;
    cin >> N;
    vector<ll> array(N),x(N),y(N); //順列の一覧
    rep(i,N){
        array.at(i) = i;
        cin >> x.at(i) >> y.at(i);
    }
    double sum = 0;
    ll length = 0;
    do{
        rep(i,N-1){
            ll fr=array.at(i),to=array.at(i+1);
            sum += sqrt(pow(x.at(to)-x.at(fr),2) + pow(y.at(to)-y.at(fr),2));
            //cout << pow(x.at(to)-x.at(fr),2) + pow(y.at(to)-y.at(fr),2) << endl;
        }
        length++;
    }while(next_permutation(array.begin(),array.end()));
    cout << fixed << setprecision(10) << sum / double(length) << endl; 
    return 0;
}
