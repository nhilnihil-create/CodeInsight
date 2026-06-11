#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    int N,M;
    cin >> N >> M;
    priority_queue<int, vector<int>> p;
    rep(i,N){
        int a;
        cin >> a;
        p.push(a);
    }
    rep(i,M){
        int a = p.top(); p.pop();
        a /= 2;
        p.push(a);
    }

    ll sum=0;
    while(!p.empty()){
        sum += p.top();
        p.pop();
    }
    cout << sum << endl;
    return 0;
}