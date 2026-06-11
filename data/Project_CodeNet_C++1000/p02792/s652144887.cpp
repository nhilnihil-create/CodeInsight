#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<utility>
using namespace std;

int n,nketa;
string s;
long long int ans=0;
map<pair<int, int>,int> mp;


pair<int,int> f(int x){
    int xf = x%10;
    while(x/10!=0){
        //cout << x << endl;
        x = x/10;
    }
    int xs = x;
    return pair<int,int> (xs,xf);
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        pair<int, int> x;
        x = f(i);
        mp[x]++;
    }

    for(int i=1;i<=n;i++){
        pair<int,int> y;
        pair<int ,int> z;
        y = f(i);
        //cout << y.first << " " << y.second << " " << i << endl;
        z = pair<int,int> (y.second,y.first);
        ans += mp[z];
    }
    cout << ans << endl;
    return 0;
}