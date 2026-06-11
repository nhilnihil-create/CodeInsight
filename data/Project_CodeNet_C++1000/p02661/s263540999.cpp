#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
#define INF 100000000000007
using namespace std;
using pii=pair<int,int>;

int median(int length,vector<int> a){/*中央値を返す．長さ偶数のときはその二倍*/
    sort(a.begin(),a.end());
    if(length%2==1){
        return a.at((length+1)/2-1);
    }else{
        return a.at(length/2-1)+a.at(length/2);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    REP(i,n){
        cin>>a.at(i)>>b.at(i);
    }

    int left,right;
    left=median(n,a);
    right=median(n,b);

    cout<<right-left+1<<endl;
    return 0;
}