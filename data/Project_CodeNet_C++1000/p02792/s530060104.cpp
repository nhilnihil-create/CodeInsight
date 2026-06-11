#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    int n;cin>>n;
    vector<vector<int>> data(10,vector<int>(10));
    ll sum =0;
    for(int i =1;i<=n;++i){
        string x = to_string(i);
        int len = x.size();
        ll first = (i/(int)pow(10,len-1))%10;
        ll second =i%10;
        data[first][second]++;

    }
    for(int i=1;i<10;++i ){
        for(int j = 1;j<10;++j){
            sum+=data[i][j]* data[j][i];
        }

    }
    cout <<sum<<endl;

}
