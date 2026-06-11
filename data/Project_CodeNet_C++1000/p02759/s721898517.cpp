#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define MOD 1e9+7;
using namespace std;
using Graph = vector<vector<int>>;
typedef vector<vector<char>> field_t;
typedef long long ll;
typedef pair<int, int> point_t;
vector<vector<pair<int,int>>> z(100010);
vector<vector<int>> a,b;
vector<bool> seen;

signed main()
{
    int N;
      cin >> N;
    if(N%2){
        cout << (N+1)/2<<endl;
    }else{
        cout << N/2 <<endl;
    }

    return 0;
}