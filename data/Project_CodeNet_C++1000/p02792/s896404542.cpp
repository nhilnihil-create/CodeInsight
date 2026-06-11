#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> count(10,vector<int>(10,0));
    for(int i=1; i<=N; i++){
        int m=i;
        vector<int> keta;
        while(m!=0){
            keta.push_back(m%10);
            m/=10;
        }
        int a,b;
        a=keta.at(0);
        b=keta.back();
        count.at(a).at(b)++;
    }
    ll ans=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            ans += count.at(i).at(j) * count.at(j).at(i);
        }
    }
    cout << ans << endl;
}
